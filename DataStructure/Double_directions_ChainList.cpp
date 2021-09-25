#include<stdio.h>
#include<stdlib.h>
#include"Function.h"

#define TRUE 1;
#define FALSE 0;
//const int TRUE = 1;

// 尾插法创建双向链表
void CreateTailList(DuLinklist * L, int n) 
{//创建大小长度为n的链表
    DuLinklist p, r;
    (*L) = (DuLNode*)malloc(sizeof(DuLNode));
    (*L)->next = NULL;
    (*L)->prior = NULL;
    (*L)->data = n;
    r = (*L);
    for (int i = 0; i < n; i++) 
    {
        p = (DuLNode*)malloc(sizeof(DuLNode));
        p->data = i;
        r->next = p;
        p->prior = r;
        r = p;
    }
    r->next = NULL;
}

//头插法建立双向链表
void CreteHeadList(DuLinklist* L, int n) 
{
    DuLinklist p, r;
    (*L) = (DuLNode*)malloc(sizeof(DuLNode));
    (*L)->next = NULL;
    (*L)->prior = NULL;
    (*L)->data = n;
    r = (*L);
    int i = 0;
    for (i = 0; i < n; i++) 
    {
        p = (DuLNode*)malloc(sizeof(DuLNode));
        p->data = i;
        if (r->next == NULL) 
        {//插入第一个节点时与其他方法不一样
            r->next = p;
            p->prior = r;
            p->next = NULL;
        }
        else 
        {
            p->next = r->next;
            r->next->prior = p;
            r->next = p;
            p->prior = r;
        }
    }
}

//获取返回最后一个节点
DuLinklist GetLast(DuLinklist* L) 
{
    DuLinklist p;
    p = (*L);
    while (p->next != NULL) 
    {
        p = p->next;
    }
    return p;
}

//在第i个位置插入元素e
void InsertElem(DuLinklist* L, int i, int e) 
{
    if (i <= (*L)->data) 
    {
        DuLinklist p, r;
        r = (*L);//指向头节点的头节点
        p = (DuLNode*)malloc(sizeof(DuLNode));//为要插入的元素申请空间
        p->data = e;
        int j = 0;
        for (j = 0; j < i; j++) 
        {//通过遍历，找到要插入的元素位置,当前r的位置
            r = r->next;
        }
        if (r->next != NULL) 
        {//节点后面有节点的时候
            p->next = r->next;
            r->next->prior = p;
            r->next = p;
            p->prior = r;

        }
        else 
        {//节点后面没有节点的情况，在最后插入元素
            r->next = p;
            p->prior = r;
            p->next = NULL;
        }
    }
    else 
    {
        printf("插入下标不合理，请重新输入\n");
    }
}

//在尾部插入节点数
void InsertTailNode(DuLinklist* L, int* dat, int num)
{
    int i;
    DuLinklist p, r;
    for (i = 0; i < num; i++)
    {
        r = GetLast(L);//指向尾节点
        p = (DuLNode*)malloc(sizeof(DuLNode));//为要插入的元素申请空间
        p->data = dat[i];
        r->next = p;
        p->prior = r;
        p->next = NULL;
    }
}

//在头部部插入节点数
void InsertHeadNode(DuLinklist* L, int* dat, int num)
{
    int i;
    DuLinklist p, r;
    r = (*L);//指向头节点
    for (i = 0; i < num; i++)
    {
        p = (DuLNode*)malloc(sizeof(DuLNode));//为要插入的元素申请空间
        p->data = dat[i];
        p->next = r->next;
        p->prior = r;
        r->next = p;
        r = r->next;
    }
}

//获取链表长度
int GetLen(DuLinklist* L)
{
    DuLinklist p;
    int len = 0;
    p = (*L);
    while (p->next != NULL)
    {
        len++;
        p = p->next;
    }
    //    printf("\nlist len:%d\n\n",len);
    return len;
}

//删除第i个位置的元素
void DeleteElem(DuLinklist* L, int i)
{
    DuLinklist p, r;
    if (i < GetLen(L) && i >= 0) 
    {
        p = (*L);
        for (int j = 0; j < i; j++) 
        {
            p = p->next;
        }
        if (p->next->next == NULL) 
        {//如果是最后一个节点
            r = p->next;//要删除的下标
            p->next = NULL;
            free(r);//释放该节点的内存
        }
        else 
        {
            r = p->next;
            p->next = r->next;
            r->next->prior = p;
            free(r);
        }
    }
    else 
    {
        printf("下标错误\n");
    }
}

//删除连续几个节点
void DeleteNumsNode(DuLinklist* L, int num) 
{

    if (num > 0 && num < GetLen(L)) 
    {

        for (int j = 0; j < num; j++) 
        {
            DeleteElem(L, 0);
        }
    }
    else 
    {
        printf("删除节点数目超出实际节点数目\n");
    }

}

//获取第i个元素
int GetElem(DuLinklist* L, int i) 
{
    int elem;
    if (i >= 0 && i <= GetLen(L)) 
    {
        DuLinklist p;
        p = (*L);

        for (int j = 0; j < i; j++) 
        {
            p = p->next;
        }
        elem = p->next->data;
        printf("\n第%d个元素:%d\n", i, elem);
        return elem;
    }
    else 
    {
        printf("error\n");
        return FALSE;
    }
}

//获取该节点的值后删除
void GetNodeVal_and_Del(DuLinklist* L, int* dat, int num)
{
    DuLinklist p;
    int i;
    p = (*L);
    for (i = 0; i < num; i++)
    {
        p = p->next;
        dat[i] = p->data;
    }
    DeleteNumsNode(L, num);
    for (i = 0; i < num; i++)
        printf("dat[%d]=%d ", i, dat[i]);
    printf("\n");
}


//顺序遍历链表
void TraverseList(DuLinklist* L) 
{
    DuLinklist p;
    p = (*L);
    while (p->next != NULL)
    {
        printf("%d ", p->next->data);
        p = p->next;
    }
    printf("\n\n");
}

//逆序遍历链表，从尾部遍历到头部，借助prior节点
void ReverTraverse(DuLinklist* L)
{
    DuLinklist p;
    p = GetLast(L);
    while (p->prior != NULL) 
    {
        printf("%d ", p->data);
        p = p->prior;
    }
    printf("\n\n");
}