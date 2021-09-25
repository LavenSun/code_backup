#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct MaxHeap
{
	int* data;
	int count;
	int maxSize;
}MH;

int MH_size(MH* mh);
int isEmpty(MH* mh);
void initMaxHeap(MH* mh, int sz);
void initMaxHeap2(MH* mh, int sz, int* arr);
void AdjustUp(MH* mh, int k);
void AdjustDown(MH* mh, int k);
void insertMAxHeap(MH* mh, int val);
int topK(MH* mh);
void sortHeap(int arr[], int n);

// priority queue
#define N 100
typedef struct PriorityQueue
{
	int _a[N];
	int _sz;
}PQ;

void PriorityQueueInit(PQ* q);
void PriorityQueuePush(PQ* q, int x);
void PQUp(PQ* q, int k);
void PriorityQueuePop(PQ* q);
void PQDown(PQ* Q, int k);
int PriorityQueueTop(PQ* q);
size_t PriorityQueueSize(PQ* q);
size_t PriorityQueueEmpty(PQ* q);
