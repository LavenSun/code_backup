#pragma once
#include<stdio.h>

typedef struct  LNode
{
	int data;
	struct  LNode* next;
}LNode, * LinkList;

bool GetElem(LinkList L, int i, int& e);

bool ListInsert(LinkList& L, int i, int e);

bool ListDelete(LinkList& L, int i, int& e);

void CreateList(int n);

void MergeList(LinkList& La, LinkList& Lb, LinkList& Lc);

typedef struct DuLNode
{
	int data;
	struct DuLNode* prior, * next;
}DuLNode, * DuLinkList;

DuLinkList GetElem(DuLinkList& L, int i);

bool ListInsert(DuLinkList& L, int i, int e);

bool ListDelete(DuLinkList& L, int i, int& e);
