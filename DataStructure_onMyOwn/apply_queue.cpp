#include<stdio.h>
#include"All_Functions.h"

/*
����ĳ������4�����ڶ���Ӵ��ͻ������������п����𲻶��пͻ��������С�
����ÿ��������ĳʱ��ֻ�ܽӴ�һ���ͻ�����˿ͻ��˶��ʱ����Ҫ�ڴ���ǰ�ӡ�
�Ըս������еĿͻ�����ĳ���ڿ��У������ǰ����4�����ڶ���ռ�ã����Զ������������ٵĶ�����档
ģ�������ҵ��������ͻ������ж�����ƽ��ʱ�䡣
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

