//Լɪ�� ��������
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"Function.h"


//����һ��ѭ������
CircleLinkList* Init_CircleLinkList() 
{
	CircleLinkList* clist = (CircleLinkList*)malloc(sizeof(CircleLinkNode));
	clist->head.next = &(clist->head);
	clist->size = 0;
	return clist;
}

//����
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

	//����λ�ò��ҽڵ�
	//����ָ���ʱ��һ��Ҫ����һ��ָ���������Ȼ�ܿ��ܸı�ָ��
	CircleLinkNode* pCurrent = &(clist->head);
	for (int i = 0; i < pos; i++) 
	{
		pCurrent = pCurrent->next;
	}
	data->next = pCurrent->next;
	pCurrent->next = data;

	clist->size++;
}

//��ȡ��һ��Ԫ��
CircleLinkNode* Front_CircleLinkList(CircleLinkList* clist) 
{
	return clist->head.next;
}

//����λ��ɾ��
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
	//����pos �ҽڵ�
	//����ָ�����
	CircleLinkNode* pCurrent = &(clist->head);
	for (int i = 0; i < pos; i++) 
	{
		pCurrent = pCurrent->next;
	}

	//���浱ǰ�ڵ����һ���ڵ�
	CircleLinkNode* pNext = pCurrent->next;
	pCurrent->next = pNext->next;

	clist->size--;
}


//����ֵɾ��
void RemoveByValue_CircleLinkList(CircleLinkList* clist, CircleLinkNode* data, COMPARENODE compare) {
	if (clist == NULL) 
	{
		return;
	}

	if (data == NULL) 
	{
		return;
	}

	//����ѭ������
	CircleLinkNode* pPrev = &(clist->head);//�ҵ���ȴ��Ԫ��ֵʱ���洢Ҫɾ����Ԫ�ص�ǰ���ڵ�
	CircleLinkNode* pCurrent = clist->head.next;//������¼ Ҫɾ����Ԫ�صĽ��
	for (int i = 0; i < clist->size; i++) 
	{
		if (compare(pCurrent, data) == CIRCLELINKLIST_TRUE) 
		{//�ҵ����
			pPrev->next = pCurrent->next;//ɾ������
			break;
		}
		pPrev = pCurrent;//�Ƚ�ָ�����
		pCurrent = pCurrent->next;//�α�ָ�����
	}
	free(pCurrent);
	clist->size--;
}


//�������ĳ���
int Size_CircleLinkList(CircleLinkList* clist)
{
	return clist->size;
}

//�ж��Ƿ�Ϊ��
int IsEmpty_CircleLinkList(CircleLinkList* clist) 
{
	if (clist->size == 0) 
	{
		return CIRCLELINKLIST_TRUE;
	}
	return CIRCLELINKLIST_FALSE;
}

//����
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

//��ӡ
void Print_CircleLinkList(CircleLinkList* clist, PRINTNODE print) 
{
	if (clist == NULL) 
	{
		return;
	}
	//����ָ�����
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

//�ͷ��ڴ�
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
	printf("ѭ������  \n");
	//����ѭ������
	CircleLinkList* clist = Init_CircleLinkList();

	//��������
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

	//��ӡ
	Print_CircleLinkList(clist, MyPrint);

	//ɾ��
	Person pDel;
	//strcpy(pDel.name, "Marvis");
	strcpy_s(pDel.name, "Marvis");
	pDel.age = 22;
	pDel.score = 92;

	RemoveByValue_CircleLinkList(clist, (CircleLinkNode*)&pDel, MyCompare);

	//��ӡ
	printf("ɾ�����ӡ \n");
	Print_CircleLinkList(clist, MyPrint);
	//�ͷ��ڴ�
	FreeSpace_CircleLinkList(clist);
	//system("pause");
	return;
}