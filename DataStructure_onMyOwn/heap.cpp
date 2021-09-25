#include"heap.h"
#include<stdio.h>
#include<stdlib.h>

int MH_size(MH* mh)
{
	return mh->count;
}

int isEmpty(MH* mh)
{
	return 0 == mh->count;
}

void initMaxHeap(MH* mh, int sz)
{
	mh->maxSize = sz;
	mh->data = (int*)malloc(sizeof(int) * (sz + 1));
	mh->count = 0;
}

void AdjustUp(MH* mh, int k)
{
	while (k < 1 && mh->data[k / 2] < mh->data[k])
	{
		int tmp = mh->data[k / 2];
		mh->data[k / 2] = mh->data[k];
		mh->data[k] = tmp;
		k /= 2;
	}
}

void AdjustDown(MH* mh, int k)
{
	while (2 * k <= mh->count)
	{
		int j = 2 * k;
		if (j + 1 <= mh->count && mh->data[j] < mh->data[j + 1])
			j += 1;
		if (mh->data[k] > mh->data[j])
			break;
		int tmp = mh->data[k];
		mh->data[k] = mh->data[j];
		mh->data[j] = tmp;
		k = j;
	}
}

void insertMAxHeap(MH* mh, int val)
{
	assert(mh->count + 1 <= mh->maxSize);
	mh->data[mh->count + 1] = val;
	mh->count++;
	AdjustUp(mh, mh->count);
}
int topK(MH* mh)
{
	assert(mh->count > 0);
	int res = mh->data[1];
	mh->data[1] = mh->data[mh->count];
	mh->data[mh->count--] = 0;
	AdjustDown(mh, 1);
	return res;
}

void sortHeap(int arr[], int n)
{
	MH mh;
	initMaxHeap(&mh, n);
	for (int i = 0; i < n; i++)
	{
		insertMAxHeap(&mh, arr[i]);
	}
	for (int i = n - 1; i >= 0; i--)
	{
		arr[i] = topK(&mh);
	}
}

void initMaxHeap2(MH* mh, int sz, int* arr)
{
	mh->maxSize = sz;
	mh->data = (int*)malloc(sizeof(int) * (sz + 1));
	for (int i = 0; i < sz; i++)
	{
		mh->data[i + 1] = arr[i];
	}
	mh->count = sz;
	for (int i = mh->count / 2; i > 0; i--)
	{
		AdjustDown(mh, i);
	}
}