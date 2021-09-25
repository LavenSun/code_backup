#pragma once
#if 0
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
}DuLNode, *DuLinkList;

DuLinkList GetElem(DuLinkList& L, int i);

bool ListInsert(DuLinkList& L, int i, int e);

bool ListDelete(DuLinkList& L, int i, int& e);


typedef struct {
	int* base; //栈底指针，构造之前和销毁之后其值都是null
	int* top; //栈顶指针，*top不存在
	int stack_size; //当前已分配的存储空间
}SqStack;

//#define STACK_INIT_SIZE 100 //存储空间初始分配量
const int STACK_INIT_SIZE = 100;
//#define STACKINCREMENT 10 //存储空间分配增量
const int STACKINCREMENT = 10;

bool InitStack(SqStack& S);

bool GetTop(SqStack S, int& e);

bool Push(SqStack& S, int e);

bool Pop(SqStack& S, int& e);


typedef struct QNode
{
	int data;
	struct QNode* next;
}QNode, * QueuePtr;

typedef struct
{
	QueuePtr front, rear;
}LinkQueue;

bool InitQueue(LinkQueue& Q);

bool DestroyQueue(LinkQueue& Q);

bool EnQueue(LinkQueue& q, int e);

bool DeQueue(LinkQueue& Q, int& e);


#define MAXQSIZE 100
typedef struct
{
	int* base;
	int front, rear;
}SqQueue;

bool InitQueue(SqQueue& Q);

int QueueLength(SqQueue Q);

bool EnQueue(SqQueue& Q, int e);

bool DeQueue(SqQueue& Q, int& e);

#define MAXSTRLEN 255
typedef unsigned char my_string[MAXSTRLEN + 1]; //my_string[0]=the length of the string

bool Concat(my_string& T, my_string s1, my_string s2);

bool SubString(my_string& sub, my_string s, int pos, int len);

typedef struct
{
	char* ch; //若字符串非空则按字符串长度分配存储区，否则为NULL
	int length;
}HString; //字符串的堆分配存储表示

bool StrInsert(HString& s, int pos, HString T);

bool StrAssign(HString& T, char* c);

int StrLength(HString s);

int StrCompare(HString s, HString t);

void ClearStr(HString& s);

bool ConCat(HString& t, HString s1, HString s2);

bool SubStr(HString& t, HString s, int pos, int len);


#define CHUNKSIZE 80
typedef struct Chunk
{
	char ch[CHUNKSIZE];
	struct Chunk* next;
}Chunk;

typedef struct
{
	Chunk* head, * tail;
	int curlen;
}LString;

//求子串位置的定位函数
int Index(my_string s, my_string t, int pos);

void getNext(my_string t, int next[]);

void getNextval(my_string t, int next[]);

int Index_KMP(my_string s, my_string t, int pos);


//稀疏矩阵的三元组顺序表存储表示
#define MAXSIZE 12500
typedef struct
{
	int i, j;
	int e;
}Triple;

typedef struct
{
	Triple data[MAXSIZE + 1];
	int mu, nu, tu;
}TSMatrix;

bool TransposeSMatrix(TSMatrix M, TSMatrix& T); //求稀疏矩阵M的转置矩阵T

bool FastTransposeSMatrix(TSMatrix M, TSMatrix& T); //求稀疏矩阵M的转置矩阵T的快速方法

#endif
