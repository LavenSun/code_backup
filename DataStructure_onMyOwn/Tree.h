#pragma once
#include<stdio.h>

typedef struct BiTNode
{
	int data;
	struct BiTNode* left_child, * right_child;
}BiTNode, * BiTree;

void PreOrderTraverse(BiTree T);

void InOrderTraverse(BiTree T);

void BackOrderTraverse(BiTree T);