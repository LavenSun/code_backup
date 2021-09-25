#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Function.h"

//动态栈 链式栈
/* 创建一个空栈 */
Stack create_stack()
{
    Stack S;

    S = (Stack)malloc(sizeof(struct stack_node));
    if (S == NULL)
        printf("malloc fair!\n");
    S->next = NULL;

    return S;
}

/* PUSH 操作 */
void push_stack(Stack s, int data)
{
    // 新建一个结点，用于存放压入栈内的元素，即新的栈顶
    PtrToNode head_node = (PtrToNode)malloc(sizeof(struct stack_node));
    if (head_node == NULL)
        printf("malloc fair!\n");

    head_node->data = data;            // 添加数据
    head_node->next = s->next;        // 新的栈顶 head_node 的 next 指针指向原来的栈顶 s->next
    s->next = head_node;            // s->next 现在指向新的栈顶
}

/* POP 操作 */
void pop_stack(Stack s)
{
    PtrToNode head_node = (PtrToNode)malloc(sizeof(struct stack_node));
    if (head_node == NULL)
        printf("malloc fair!\n");

    // 先判断栈是否为空，若栈为空，则不能再进行出栈操作，报错
    if (stack_is_empty(s)) {
        printf("Error! Stack is empty!\n");
    }
    else {
        head_node = s->next;            // head_node 为栈顶
        s->next = head_node->next;        // s->next 指向 head_node->next ，即新的栈顶
        free(head_node);                // 释放原来栈顶元素所占的内存
    }
}

/* 查看栈顶元素 */
int top_stack(Stack s)
{
    if (stack_is_empty(s)) {
        printf("Error! Stack is empty!\n");
        return 0;
    }
    else {
        return s->next->data;
    }
}

/* 判断栈是否为空 */
int stack_is_empty(Stack s)
{
    return s->next == NULL;
}

void UseStack()
{
    Stack stack = create_stack();        // 新建一个空栈
    int top_data, i;
    // 压栈操作，执行10次
    for (i = 0; i < 10; i++) {
        push_stack(stack, i);
    }
    // 出栈操作，执行1次
    pop_stack(stack);
    // 返回栈顶元素的值
    top_data = top_stack(stack);
    printf("%d\n", top_data);
    return;
}