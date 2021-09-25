#include<stdio.h>
#include<stdlib.h>
#include"Function.h"

/* ����һ��ջ */
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

/* ����һ����ջ */
void make_empty_Array(Stack_Array s)
{
    // ջ�����±�Ϊ -1 ��ʾջΪ��
    s->top_of_stack = EmptyTOS;
}

/* PUSH ���� */
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

/* POP ���� */
void pop_stack_Array(Stack_Array s)
{
    if (stack_is_empty_Array(s)) {
        printf("Error! Stack is empty!\n");
    }
    else {
        s->top_of_stack--;
    }
}

/* ����ջ��Ԫ�� */
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

/* ���ջ�Ƿ�Ϊ��ջ */
int stack_is_empty_Array(Stack_Array s)
{
    // ջ�����±�Ϊ -1 ��ʾջΪ��
    return s->top_of_stack == EmptyTOS;
}


/* ���ջ�Ƿ�Ϊ��ջ */
int stack_is_full_Array(Stack_Array s)
{
    // ջ�����±�Ϊ capacity - 1 ��ʾջ���ˣ������±�� 0 ��ʼ��
    return s->top_of_stack == --s->capacity;
}