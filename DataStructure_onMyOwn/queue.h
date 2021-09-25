#pragma once
#include<stdio.h>

typedef struct QNode
{
	int data;
	struct QNode* next;
}QNode, * QueuePtr;

typedef struct
{
	QueuePtr front, rear;
}LinkQueue;

bool InitQueue(LinkQueue& Q);

bool DestroyQueue(LinkQueue& Q);

bool EnQueue(LinkQueue& q, int e);

bool DeQueue(LinkQueue& Q, int& e);

#define MAXQSIZE 100
typedef struct
{
	int* base;
	int front, rear;
}SqQueue;

bool InitQueue(SqQueue& Q);

int QueueLength(SqQueue Q);

bool EnQueue(SqQueue& Q, int e);

bool DeQueue(SqQueue& Q, int& e);

