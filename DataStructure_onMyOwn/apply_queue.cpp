#include<stdio.h>
#include"All_Functions.h"

/*
假设某银行有4个窗口对外接待客户，从早上银行开门起不断有客户进入银行。
由于每个窗口在某时刻只能接待一个客户，因此客户人多的时候需要在窗口前队。
对刚进入银行的客户，若某窗口空闲，则可上前；若4个窗口都被占用，则自动排在人数最少的队伍后面。
模拟该银行业务活动并计算客户在银行逗留的平均时间。
*/

typedef struct
{
	int OccurTime;
	int NType;
}Event, ElemType;

typedef LinkList EventList;

typedef struct
{
	int ArrivalTime;
	int Duration;
}QElemType;

