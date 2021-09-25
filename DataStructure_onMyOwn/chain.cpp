#include<stdio.h>
#include"chain.h"
#include <malloc.h>

bool GetElem(LinkList L, int i, int& e)
{
	LNode* p = L->next;
	int j = 1;
	while (p && j < i)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i)
		return false;
	e = p->data;
	return true;
}

bool ListInsert(LinkList& L, int i, int e)
{
	int j = 0;
	LinkList p = L;
	while (p && j < i - 1)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i)
		return false;
	LinkList s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

bool ListDelete(LinkList& L, int i, int& e)
{
	LinkList p = L;
	int j = 0;
	while (p->next && j < i - 1)
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i - 1)
		return false;
	e = p->next->data;
	p->next = p->next->next;
	return true;
}

void CreateList(int n)
{
	LinkList L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	int tmp;
	for (int i = n; i > 0; --i)
	{
		LinkList p = (LinkList)malloc(sizeof(LNode));
		printf("Input a number:\n");
		scanf_s("%d", &tmp);
		p->data = tmp;
		p->next = L->next;
		L->next = p;
	}
	return;
}

void MergeList(LinkList& La, LinkList& Lb, LinkList& Lc)
{
	LinkList pa = La->next, pb = Lb->next;
	LinkList pc;
	Lc = pc = La;
	while (pa && pb)
	{
		if (pa->data <= pb->data)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	pc->next = pa ? pa : pb;
	free(Lb);
	return;
}

bool GetElem(DuLinkList L, int i, int& e)
{
	DuLNode* p = L->next;
	int j = 1;
	while (p && j < i)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i)
		return false;
	e = p->data;
	return true;
}

DuLinkList GetElem(DuLinkList& L, int i)
{
	DuLinkList p = L;
	int j = 0;
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	return p;
}

bool ListInsert(DuLinkList& L, int i, int e)
{
	DuLinkList p;
	if (!(p = GetElem(L, i)))
		return false;
	DuLinkList s = (DuLinkList)malloc(sizeof(DuLNode));
	if (!s)
		return false;
	s->data = e;
	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->prior = s;
	return true;
}

bool ListDelete(DuLinkList& L, int i, int& e)
{
	DuLinkList p = GetElem(L, i);
	if (!p)
		return false;
	e = p->data;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	delete p;
	return true;
}

