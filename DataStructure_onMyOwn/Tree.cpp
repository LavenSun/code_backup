#include<stdio.h>
#include"Tree.h"
#include <malloc.h>

void PreOrderTraverse(BiTree T)
{
	if (T)
	{
		if (T->data)
			printf("%d ", T->data);
		PreOrderTraverse(T->left_child);
		PreOrderTraverse(T->right_child);
	}
	return;
}

void InOrderTraverse(BiTree T)
{
	if (T)
	{
		PreOrderTraverse(T->left_child);
		if (T->data)
			printf("%d ", T->data);
		PreOrderTraverse(T->right_child);
	}
	return;
}

void BackOrderTraverse(BiTree T)
{
	if (T)
	{
		PreOrderTraverse(T->left_child);
		PreOrderTraverse(T->right_child);
		if (T->data)
			printf("%d ", T->data);
	}
	return;
}