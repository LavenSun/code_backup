#include<stdio.h>
#include<stdlib.h>
#include"Function.h"

/* 创建一个栈 */
Stack_Array create_stack_Array(int stack_capacity)
{
    Stack_Array S;

    if (stack_capacity < MinStackSize)
        printf("Error! Stack size is too small!\n");

    S = (Stack_Array)malloc(sizeof(struct stack_array));
    if (S == NULL)
        printf("malloc error!\n");

    S->array = (int*)malloc(sizeof(struct stack_array) * stack_capacity);
    if (S->array == NULL)
        printf("malloc error!\n");
    S->capacity = stack_capacity;

    make_empty_Array(S);
    return S;
}

/* 创建一个空栈 */
void make_empty_Array(Stack_Array s)
{
    // 栈顶的下标为 -1 表示栈为空
    s->top_of_stack = EmptyTOS;
}

/* PUSH 操作 */
void push_stack_Array(Stack_Array s, int data)
{
    if (stack_is_full_Array(s)) {
        printf("Error! Stack is full!\n");
    }
    else {
        s->top_of_stack++;
        s->array[s->top_of_stack] = data;
    }
}

/* POP 操作 */
void pop_stack_Array(Stack_Array s)
{
    if (stack_is_empty_Array(s)) {
        printf("Error! Stack is empty!\n");
    }
    else {
        s->top_of_stack--;
    }
}

/* 返回栈顶元素 */
int top_stack_Array(Stack_Array s)
{
    if (stack_is_empty_Array(s)) {
        printf("Error! Stack is empty!\n");
        return 0;
    }
    else {
        return s->array[s->top_of_stack];
    }
}

/* 检测栈是否为空栈 */
int stack_is_empty_Array(Stack_Array s)
{
    // 栈顶的下标为 -1 表示栈为空
    return s->top_of_stack == EmptyTOS;
}


/* 检测栈是否为满栈 */
int stack_is_full_Array(Stack_Array s)
{
    // 栈顶的下标为 capacity - 1 表示栈满了（数组下标从 0 开始）
    return s->top_of_stack == --s->capacity;
}