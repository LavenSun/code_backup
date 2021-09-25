//约瑟夫环 环形链表
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"Function.h"


//创建一个循环链表
CircleLinkList* Init_CircleLinkList() 
{
	CircleLinkList* clist = (CircleLinkList*)malloc(sizeof(CircleLinkNode));
	clist->head.next = &(clist->head);
	clist->size = 0;
	return clist;
}

//插入
void Insert_CircleLinkList(CircleLinkList* clist, int pos, CircleLinkNode* data) 
{
	if (clist == NULL) 
	{
		return;
	}

	if (data == NULL) 
	{
		return;
	}

	if (pos < 0 || pos > clist->size) 
	{
		pos = clist->size;
	}

	//根据位置查找节点
	//操作指针的时候一定要引入一个指针变量，不然很可能改变指针
	CircleLinkNode* pCurrent = &(clist->head);
	for (int i = 0; i < pos; i++) 
	{
		pCurrent = pCurrent->next;
	}
	data->next = pCurrent->next;
	pCurrent->next = data;

	clist->size++;
}

//获取第一个元素
CircleLinkNode* Front_CircleLinkList(CircleLinkList* clist) 
{
	return clist->head.next;
}

//根据位置删除
void RemoveByPos_CircleLinkList(CircleLinkList* clist, int pos) 
{
	if (clist == NULL) 
	{
		return;
	}

	if (pos < 0 || pos >= clist->size) 
	{
		return;
	}
	//根据pos 找节点
	//辅助指针变量
	CircleLinkNode* pCurrent = &(clist->head);
	for (int i = 0; i < pos; i++) 
	{
		pCurrent = pCurrent->next;
	}

	//缓存当前节点的下一个节点
	CircleLinkNode* pNext = pCurrent->next;
	pCurrent->next = pNext->next;

	clist->size--;
}


//根据值删除
void RemoveByValue_CircleLinkList(CircleLinkList* clist, CircleLinkNode* data, COMPARENODE compare) {
	if (clist == NULL) 
	{
		return;
	}

	if (data == NULL) 
	{
		return;
	}

	//这是循环链表
	CircleLinkNode* pPrev = &(clist->head);//找到相等打的元素值时，存储要删除的元素的前驱节点
	CircleLinkNode* pCurrent = clist->head.next;//用来记录 要删除的元素的结点
	for (int i = 0; i < clist->size; i++) 
	{
		if (compare(pCurrent, data) == CIRCLELINKLIST_TRUE) 
		{//找点操作
			pPrev->next = pCurrent->next;//删除操作
			break;
		}
		pPrev = pCurrent;//比较指针后移
		pCurrent = pCurrent->next;//游标指针后移
	}
	free(pCurrent);
	clist->size--;
}


//获得链表的长度
int Size_CircleLinkList(CircleLinkList* clist)
{
	return clist->size;
}

//判断是否为空
int IsEmpty_CircleLinkList(CircleLinkList* clist) 
{
	if (clist->size == 0) 
	{
		return CIRCLELINKLIST_TRUE;
	}
	return CIRCLELINKLIST_FALSE;
}

//查找
int Find_CircleLinkList(CircleLinkList* clist, CircleLinkNode* data, COMPARENODE compare) 
{
	if (clist == NULL) 
	{
		return -1;
	}

	if (data == NULL) 
	{
		return -1;
	}
	CircleLinkNode* pCurrent = clist->head.next;
	int flag = -1;
	for (int i = 0; i < clist->size; i++) 
	{
		if (compare(pCurrent, data) == CIRCLELINKLIST_TRUE) 
		{
			flag = i;
			break;
		}
		pCurrent = pCurrent->next;
	}

	return flag;
}

//打印
void Print_CircleLinkList(CircleLinkList* clist, PRINTNODE print) 
{
	if (clist == NULL) 
	{
		return;
	}
	//辅助指针变量
	CircleLinkNode* pCurrent = clist->head.next;
	for (int i = 0; i < clist->size; i++) 
	{
		if (pCurrent == pCurrent->next) 
		{
			pCurrent = pCurrent->next;
		}
		print(pCurrent);
		pCurrent = pCurrent->next;
	}
}

//释放内存
void FreeSpace_CircleLinkList(CircleLinkList* clist)
{
	if (clist == NULL) 
	{
		return;
	}
	free(clist);
}

typedef struct PERSON 
{
	CircleLinkNode node;
	char name[64];
	int age;
	int score;
}Person;
void MyPrint(CircleLinkNode* data) 
{
	Person* p = (Person*)data;
	printf("name: %s , age: %d, score: %d \n", p->name, p->age, p->score);
}

int MyCompare(CircleLinkNode* data1, CircleLinkNode* data2) 
{
	Person* p1 = (Person*)data1;
	Person* p2 = (Person*)data2;

	if (strcmp(p1->name, p2->name) == 0 && p1->age == p2->age && p1->score == p2->score) 
	{
		return CIRCLELINKLIST_TRUE;
	}
}

void Use_Circle_ChainList()
{
	printf("循环链表  \n");
	//创建循环链表
	CircleLinkList* clist = Init_CircleLinkList();

	//创建数据
	Person p1, p2, p3, p4, p5;
	//strcpy(p1.name, "jarvis");
	//strcpy(p2.name, "marvis");
	//strcpy(p3.name, "harvis");
	//strcpy(p4.name, "larvis");
	//strcpy(p5.name, "karvis");
	strcpy_s(p1.name, "jarvis");
	strcpy_s(p2.name, "marvis");
	strcpy_s(p3.name, "harvis");
	strcpy_s(p4.name, "larvis");
	strcpy_s(p5.name, "karvis"); 

	p1.age = 21;
	p2.age = 22;
	p3.age = 23;
	p4.age = 24;
	p5.age = 25;

	p1.score = 91;
	p2.score = 92;
	p3.score = 93;
	p4.score = 94;
	p5.score = 95;


	Insert_CircleLinkList(clist, 0, (CircleLinkNode*)&p1);
	Insert_CircleLinkList(clist, 1, (CircleLinkNode*)&p2);
	Insert_CircleLinkList(clist, 2, (CircleLinkNode*)&p3);
	Insert_CircleLinkList(clist, 3, (CircleLinkNode*)&p4);
	Insert_CircleLinkList(clist, 4, (CircleLinkNode*)&p5);

	//打印
	Print_CircleLinkList(clist, MyPrint);

	//删除
	Person pDel;
	//strcpy(pDel.name, "Marvis");
	strcpy_s(pDel.name, "Marvis");
	pDel.age = 22;
	pDel.score = 92;

	RemoveByValue_CircleLinkList(clist, (CircleLinkNode*)&pDel, MyCompare);

	//打印
	printf("删除后打印 \n");
	Print_CircleLinkList(clist, MyPrint);
	//释放内存
	FreeSpace_CircleLinkList(clist);
	//system("pause");
	return;
}