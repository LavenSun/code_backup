#include <stdio.h>
#include "queue.h"
#include <malloc.h>

bool InitQueue(LinkQueue& Q)
{
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q.front)
		return false;
	Q.front->next = NULL;
	return true;
}

bool DestroyQueue(LinkQueue& Q)
{
	while (Q.front)
	{
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
	return true;
}

bool EnQueue(LinkQueue& Q, int e)
{
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)
		return false;
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return true;
}

bool DeQueue(LinkQueue& Q, int& e)
{
	if (Q.front == Q.rear)
		return false;
	QNode* p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)
		Q.rear = Q.front;
	free(p);
	return true;
}

bool InitQueue(SqQueue& Q)
{
	Q.base = (int*)malloc(MAXQSIZE * sizeof(int));
	if (!Q.base)
		return false;
	Q.front = Q.rear = 0;
	return true;
}

int QueueLength(SqQueue Q)
{
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

bool EnQueue(SqQueue& Q, int e)
{
	if ((Q.rear + 1) % MAXQSIZE == Q.front)
		return false;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
	return true;
}

bool DeQueue(SqQueue& Q, int& e)
{
	if (Q.front == Q.rear)
		return false;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE;
	return true;
}



