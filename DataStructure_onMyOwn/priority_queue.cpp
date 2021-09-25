#include"heap.h"
#include<stdio.h>
#include<stdlib.h>

void PriorityQueueInit(PQ* q)
{
	assert(q);
	q->_sz = 0;
}

void PriorityQueuePush(PQ* q, int x)
{
	assert(q);
	assert(q->_sz <= N);
	q->_a[q->_sz++] = x;
}

void PQUp(PQ* q, int k)
{

}
void PriorityQueuePop(PQ* q)
{
	assert(q);
	if (q->_sz == 0)
		return;
	MH mh;
	initMaxHeap2(&mh, q->_sz, q->_a);
}

void PQDown(PQ* Q, int k)
{

}

int PriorityQueueTop(PQ* q)
{
	assert(q);
	if (q->_sz == 0)
	{
		return;
	}
	MH mh;
	initMaxHeap2(&mh, q->_sz, q->_a);
	return mh.data[1];
}

size_t PriorityQueueSize(PQ* q)
{
	return q->_sz;
}

size_t PriorityQueueEmpty(PQ* q)
{
	return 0 == q->_sz;
}