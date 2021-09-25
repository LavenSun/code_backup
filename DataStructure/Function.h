#pragma once
#include<stdio.h>
#include<stdlib.h>

/* 顺序队列接口定义头文件*/
#define true 1
#define false 0

/* 队的最大长度 */
#define MAX_QUEUE_SIZE 100

/* 队列的数据类型 */
typedef int datatype;

typedef struct Link //单向链表
{
    char elem;//代表数据域
    struct Link* next;//代表指针域，指向直接后继元素
}link;

link* initLink();

int selectElem(link* p, int elem);

link* amendElem(link* p, int add, int newElem);

link* insertElem(link* p, int elem, int add);

link* delElem(link* p, int add);

void display(link* p);

int UseChainList();


/* 静态链的数据结构 */
typedef struct queue 
{
    datatype sp_queue_array[MAX_QUEUE_SIZE];
    /* 队头 */
    int front;
    /* 队尾 */
    int rear;
}sp_queue;

/* 静态链的初始化 */
sp_queue queue_init();

/* 判断队列是否为空,若为空
 * 返回true
 * 否则返回false
*/
int queue_empty(sp_queue q);


/* 插入元素e为队q的队尾新元素
 * 插入成功返回true
 * 队满返回false
*/
int queue_en(sp_queue* q, datatype e);


/* 队头元素出队
 * 用e返回出队元素,并返回true
 * 若队空返回false
*/
int queue_de(sp_queue* q, datatype* e);

/* 清空队 */
void queue_clear(sp_queue* q);

/* 获得队头元素
 * 队列非空,用e返回队头元素,并返回true
 * 否则返回false
*/
int get_front(sp_queue, datatype* e);

/* 获得队长 */
int queue_len(sp_queue q);

/* 遍历队 */
void queue_traverse(sp_queue q, void(*visit)(sp_queue q));

void visit(sp_queue s);

void UseQueue1();



typedef struct linkqueuenode 
{       //使用单链表记录数据的入队（队头添加节点）和出队（队尾删除节点）
    datatype data;                 /*数据域*/
    struct linkqueuenode* next;      	/*链接指针域*/
}linkqueue_node, * linkqueue_pnode;     /*链表元素类型定义*/

typedef struct linkqueue 
{           //定义一个结构体，记录队列（单链表）中的头结点和尾节点
    linkqueue_pnode front, rear;
}link_queue, * link_pqueue;

extern void init_linkqueue(link_pqueue* Q);          //创建队列

extern bool is_empty_linkqueue(link_pqueue q);            //判断队列是否为空

extern bool in_linkqueue(datatype data, link_pqueue q);      //入队

extern bool out_linkqueue(link_pqueue q, datatype* D);     //出队

extern void show_linkqueue(link_pqueue q);            //依次显示队头到队尾的数据

extern void free_linkqueue(link_pqueue q);           //释放队列


struct stack_node {
    int data;
    struct stack_node* next;
};

typedef struct stack_node* PtrToNode;
typedef PtrToNode Stack;

Stack create_stack();

void push_stack(Stack s, int data);

void pop_stack(Stack s);

int top_stack(Stack s);

int stack_is_empty(Stack s);

void UseStack();


//静态栈 栈的数组实现
#define MinStackSize 5
#define EmptyTOS -1

struct stack_array 
{
    int capacity;            // 栈的容量
    int top_of_stack;        // 栈顶的下标
    int* array;                // 用于存放栈的数组
};

typedef struct stack_array* ArrayRecord;
typedef ArrayRecord Stack_Array;

Stack_Array create_stack_Array(int stack_capacity);

void make_empty_Array(Stack_Array s);

void push_stack_Array(Stack_Array s, int data);

int top_stack_Array(Stack_Array s);

void pop_stack_Array(Stack_Array s);

int stack_is_empty_Array(Stack_Array s);

int stack_is_full_Array(Stack_Array s);


//环形链表
#ifndef SRC_CYCLELINKLIST_H_
#define SRC_CYCLELINKLIST_H_

#define CIRCLELINKLIST_TRUE 1
#define CIRCLELINKLIST_FALSE 0

/**
 * 1、循环链表，带头节点，初始化的时候，和单向链表不一样的地方，头节点不指向NULL，而是指向自己head
 * 2、循环链表的判满 1）判断next是不是头结点，2）判断size
 * */

 //链表的小节点
typedef struct CIRCLELINKNODE 
{
    struct CIRCLELINKNODE* next;
}CircleLinkNode;


//结构体
typedef struct CIRCLELINKLIST 
{
    CircleLinkNode head;
    int size;
}CircleLinkList;

//比较回调
typedef int(*COMPARENODE)(CircleLinkNode*, CircleLinkNode*);

typedef void(*PRINTNODE)(CircleLinkNode*);

//API
//创建一个循环链表
CircleLinkList* Init_CircleLinkList();

//插入
void Insert_CircleLinkList(CircleLinkList* clist, int pos, CircleLinkNode* data);

//获取第一个元素
CircleLinkNode* Front_CircleLinkList(CircleLinkList* clist);

//根据位置删除
void RemoveByPos_CircleLinkList(CircleLinkList* clist, int pos);

//根据值删除
void RemoveByValue_CircleLinkList(CircleLinkList* clist, CircleLinkNode* data, COMPARENODE compare);


//获得链表的长度
int Size_CircleLinkList(CircleLinkList* clist);

//判断是否为空
int IsEmpty_CircleLinkList(CircleLinkList* clist);
//查找
int Find_CircleLinkList(CircleLinkList* clist, CircleLinkNode* data, COMPARENODE compare);

//打印
void Print_CircleLinkList(CircleLinkList* clist, PRINTNODE print);

//释放内存
void FreeSpace_CircleLinkList(CircleLinkList* clist);

void Use_Circle_ChainList();

#endif /* SRC_CYCLELINKLIST_H_ */


//双向链表
typedef struct DuLNode 
{
    struct DuLNode* prior, * next;
    int data;
}DuLNode, * DuLinklist;

// 尾插法创建双向链表
void CreateTailList(DuLinklist* L, int n);

//头插法建立双向链表
void CreteHeadList(DuLinklist* L, int n);

//获取返回最后一个节点
DuLinklist GetLast(DuLinklist* L);

//在第i个位置插入元素e
void InsertElem(DuLinklist* L, int i, int e);

//在尾部插入节点数
void InsertTailNode(DuLinklist* L, int* dat, int num);

//在头部部插入节点数
void InsertHeadNode(DuLinklist* L, int* dat, int num);

//获取链表长度
int GetLen(DuLinklist* L);

//删除第i个位置的元素
void DeleteElem(DuLinklist* L, int i);

//删除连续几个节点
void DeleteNumsNode(DuLinklist* L, int num);

//获取第i个元素
int GetElem(DuLinklist* L, int i);

//获取该节点的值后删除
void GetNodeVal_and_Del(DuLinklist* L, int* dat, int num);

//顺序遍历链表
void TraverseList(DuLinklist* L);

//逆序遍历链表，从尾部遍历到头部，借助prior节点
void ReverTraverse(DuLinklist* L);