#pragma once
#include<stdio.h>

typedef struct {
	int* base; //ջ��ָ�룬����֮ǰ������֮����ֵ����null
	int* top; //ջ��ָ�룬*top������
	int stack_size; //��ǰ�ѷ���Ĵ洢�ռ�
}SqStack;

//#define STACK_INIT_SIZE 100 //�洢�ռ��ʼ������
const int STACK_INIT_SIZE = 100;
//#define STACKINCREMENT 10 //�洢�ռ��������
const int STACKINCREMENT = 10;

bool InitStack(SqStack& S);

bool GetTop(SqStack S, int& e);

bool Push(SqStack& S, int e);

bool Pop(SqStack& S, int& e);

