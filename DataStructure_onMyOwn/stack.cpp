#include<stdio.h>
#include"stack.h"
#include <malloc.h>

bool InitStack(SqStack& S)
{
	S.base = (int*)malloc(STACK_INIT_SIZE * sizeof(int));
	if (!S.base)
		return false;
	S.top = S.base;
	S.stack_size = STACK_INIT_SIZE;
	return true;
}

bool GetTop(SqStack S, int& e)
{
	if (S.top == S.base)
		return false;
	e = *(S.top - 1);
	return true;
}

bool Push(SqStack& S, int e)
{
	if (S.top - S.base >= S.stack_size)
	{
		S.base = (int*)realloc(S.base, (S.stack_size + STACKINCREMENT) * sizeof(int));
		if (!S.base)
			return false;
		S.top = S.base + S.stack_size;
		S.stack_size += STACKINCREMENT;
	}
	*S.top++ = e;
	return true;
}

bool Pop(SqStack& S, int& e)
{
	if (S.top == S.base)
		return false;
	e = *--S.top;
	return true;
}

//n阶汉诺塔问题递归求解
int c = 0;
void move(char x, int n, char y)
{
	printf("%i.Move disk %i from %c to %c\n", ++c, n, x, y);
	return;
}
void hanoi(int n, char x, char y, char z)
{
	if (n == 1)
		move(x, 1, z);
	else
	{
		hanoi(n - 1, x, z, y);
		move(x, n, z);
		hanoi(n - 1, y, x, z);
	}
	return;
}

