#pragma once
#include<stdio.h>

typedef struct {
	int* base; //栈底指针，构造之前和销毁之后其值都是null
	int* top; //栈顶指针，*top不存在
	int stack_size; //当前已分配的存储空间
}SqStack;

//#define STACK_INIT_SIZE 100 //存储空间初始分配量
const int STACK_INIT_SIZE = 100;
//#define STACKINCREMENT 10 //存储空间分配增量
const int STACKINCREMENT = 10;

bool InitStack(SqStack& S);

bool GetTop(SqStack S, int& e);

bool Push(SqStack& S, int e);

bool Pop(SqStack& S, int& e);

