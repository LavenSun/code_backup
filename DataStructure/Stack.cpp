#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Function.h"

//��̬ջ ��ʽջ
/* ����һ����ջ */
Stack create_stack()
{
    Stack S;

    S = (Stack)malloc(sizeof(struct stack_node));
    if (S == NULL)
        printf("malloc fair!\n");
    S->next = NULL;

    return S;
}

/* PUSH ���� */
void push_stack(Stack s, int data)
{
    // �½�һ����㣬���ڴ��ѹ��ջ�ڵ�Ԫ�أ����µ�ջ��
    PtrToNode head_node = (PtrToNode)malloc(sizeof(struct stack_node));
    if (head_node == NULL)
        printf("malloc fair!\n");

    head_node->data = data;            // �������
    head_node->next = s->next;        // �µ�ջ�� head_node �� next ָ��ָ��ԭ����ջ�� s->next
    s->next = head_node;            // s->next ����ָ���µ�ջ��
}

/* POP ���� */
void pop_stack(Stack s)
{
    PtrToNode head_node = (PtrToNode)malloc(sizeof(struct stack_node));
    if (head_node == NULL)
        printf("malloc fair!\n");

    // ���ж�ջ�Ƿ�Ϊ�գ���ջΪ�գ������ٽ��г�ջ����������
    if (stack_is_empty(s)) {
        printf("Error! Stack is empty!\n");
    }
    else {
        head_node = s->next;            // head_node Ϊջ��
        s->next = head_node->next;        // s->next ָ�� head_node->next �����µ�ջ��
        free(head_node);                // �ͷ�ԭ��ջ��Ԫ����ռ���ڴ�
    }
}

/* �鿴ջ��Ԫ�� */
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

/* �ж�ջ�Ƿ�Ϊ�� */
int stack_is_empty(Stack s)
{
    return s->next == NULL;
}

void UseStack()
{
    Stack stack = create_stack();        // �½�һ����ջ
    int top_data, i;
    // ѹջ������ִ��10��
    for (i = 0; i < 10; i++) {
        push_stack(stack, i);
    }
    // ��ջ������ִ��1��
    pop_stack(stack);
    // ����ջ��Ԫ�ص�ֵ
    top_data = top_stack(stack);
    printf("%d\n", top_data);
    return;
}