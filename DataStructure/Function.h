#pragma once
#include<stdio.h>
#include<stdlib.h>

/* ˳����нӿڶ���ͷ�ļ�*/
#define true 1
#define false 0

/* �ӵ���󳤶� */
#define MAX_QUEUE_SIZE 100

/* ���е��������� */
typedef int datatype;

typedef struct Link //��������
{
    char elem;//����������
    struct Link* next;//����ָ����ָ��ֱ�Ӻ��Ԫ��
}link;

link* initLink();

int selectElem(link* p, int elem);

link* amendElem(link* p, int add, int newElem);

link* insertElem(link* p, int elem, int add);

link* delElem(link* p, int add);

void display(link* p);

int UseChainList();


/* ��̬�������ݽṹ */
typedef struct queue 
{
    datatype sp_queue_array[MAX_QUEUE_SIZE];
    /* ��ͷ */
    int front;
    /* ��β */
    int rear;
}sp_queue;

/* ��̬���ĳ�ʼ�� */
sp_queue queue_init();

/* �ж϶����Ƿ�Ϊ��,��Ϊ��
 * ����true
 * ���򷵻�false
*/
int queue_empty(sp_queue q);


/* ����Ԫ��eΪ��q�Ķ�β��Ԫ��
 * ����ɹ�����true
 * ��������false
*/
int queue_en(sp_queue* q, datatype e);


/* ��ͷԪ�س���
 * ��e���س���Ԫ��,������true
 * ���ӿշ���false
*/
int queue_de(sp_queue* q, datatype* e);

/* ��ն� */
void queue_clear(sp_queue* q);

/* ��ö�ͷԪ��
 * ���зǿ�,��e���ض�ͷԪ��,������true
 * ���򷵻�false
*/
int get_front(sp_queue, datatype* e);

/* ��öӳ� */
int queue_len(sp_queue q);

/* ������ */
void queue_traverse(sp_queue q, void(*visit)(sp_queue q));

void visit(sp_queue s);

void UseQueue1();



typedef struct linkqueuenode 
{       //ʹ�õ������¼���ݵ���ӣ���ͷ��ӽڵ㣩�ͳ��ӣ���βɾ���ڵ㣩
    datatype data;                 /*������*/
    struct linkqueuenode* next;      	/*����ָ����*/
}linkqueue_node, * linkqueue_pnode;     /*����Ԫ�����Ͷ���*/

typedef struct linkqueue 
{           //����һ���ṹ�壬��¼���У��������е�ͷ����β�ڵ�
    linkqueue_pnode front, rear;
}link_queue, * link_pqueue;

extern void init_linkqueue(link_pqueue* Q);          //��������

extern bool is_empty_linkqueue(link_pqueue q);            //�ж϶����Ƿ�Ϊ��

extern bool in_linkqueue(datatype data, link_pqueue q);      //���

extern bool out_linkqueue(link_pqueue q, datatype* D);     //����

extern void show_linkqueue(link_pqueue q);            //������ʾ��ͷ����β������

extern void free_linkqueue(link_pqueue q);           //�ͷŶ���


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


//��̬ջ ջ������ʵ��
#define MinStackSize 5
#define EmptyTOS -1

struct stack_array 
{
    int capacity;            // ջ������
    int top_of_stack;        // ջ�����±�
    int* array;                // ���ڴ��ջ������
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


//��������
#ifndef SRC_CYCLELINKLIST_H_
#define SRC_CYCLELINKLIST_H_

#define CIRCLELINKLIST_TRUE 1
#define CIRCLELINKLIST_FALSE 0

/**
 * 1��ѭ��������ͷ�ڵ㣬��ʼ����ʱ�򣬺͵�������һ���ĵط���ͷ�ڵ㲻ָ��NULL������ָ���Լ�head
 * 2��ѭ����������� 1���ж�next�ǲ���ͷ��㣬2���ж�size
 * */

 //�����С�ڵ�
typedef struct CIRCLELINKNODE 
{
    struct CIRCLELINKNODE* next;
}CircleLinkNode;


//�ṹ��
typedef struct CIRCLELINKLIST 
{
    CircleLinkNode head;
    int size;
}CircleLinkList;

//�Ƚϻص�
typedef int(*COMPARENODE)(CircleLinkNode*, CircleLinkNode*);

typedef void(*PRINTNODE)(CircleLinkNode*);

//API
//����һ��ѭ������
CircleLinkList* Init_CircleLinkList();

//����
void Insert_CircleLinkList(CircleLinkList* clist, int pos, CircleLinkNode* data);

//��ȡ��һ��Ԫ��
CircleLinkNode* Front_CircleLinkList(CircleLinkList* clist);

//����λ��ɾ��
void RemoveByPos_CircleLinkList(CircleLinkList* clist, int pos);

//����ֵɾ��
void RemoveByValue_CircleLinkList(CircleLinkList* clist, CircleLinkNode* data, COMPARENODE compare);


//�������ĳ���
int Size_CircleLinkList(CircleLinkList* clist);

//�ж��Ƿ�Ϊ��
int IsEmpty_CircleLinkList(CircleLinkList* clist);
//����
int Find_CircleLinkList(CircleLinkList* clist, CircleLinkNode* data, COMPARENODE compare);

//��ӡ
void Print_CircleLinkList(CircleLinkList* clist, PRINTNODE print);

//�ͷ��ڴ�
void FreeSpace_CircleLinkList(CircleLinkList* clist);

void Use_Circle_ChainList();

#endif /* SRC_CYCLELINKLIST_H_ */


//˫������
typedef struct DuLNode 
{
    struct DuLNode* prior, * next;
    int data;
}DuLNode, * DuLinklist;

// β�巨����˫������
void CreateTailList(DuLinklist* L, int n);

//ͷ�巨����˫������
void CreteHeadList(DuLinklist* L, int n);

//��ȡ�������һ���ڵ�
DuLinklist GetLast(DuLinklist* L);

//�ڵ�i��λ�ò���Ԫ��e
void InsertElem(DuLinklist* L, int i, int e);

//��β������ڵ���
void InsertTailNode(DuLinklist* L, int* dat, int num);

//��ͷ��������ڵ���
void InsertHeadNode(DuLinklist* L, int* dat, int num);

//��ȡ������
int GetLen(DuLinklist* L);

//ɾ����i��λ�õ�Ԫ��
void DeleteElem(DuLinklist* L, int i);

//ɾ�����������ڵ�
void DeleteNumsNode(DuLinklist* L, int num);

//��ȡ��i��Ԫ��
int GetElem(DuLinklist* L, int i);

//��ȡ�ýڵ��ֵ��ɾ��
void GetNodeVal_and_Del(DuLinklist* L, int* dat, int num);

//˳���������
void TraverseList(DuLinklist* L);

//�������������β��������ͷ��������prior�ڵ�
void ReverTraverse(DuLinklist* L);