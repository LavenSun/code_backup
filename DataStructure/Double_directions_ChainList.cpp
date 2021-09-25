#include<stdio.h>
#include<stdlib.h>
#include"Function.h"

#define TRUE 1;
#define FALSE 0;
//const int TRUE = 1;

// β�巨����˫������
void CreateTailList(DuLinklist * L, int n) 
{//������С����Ϊn������
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

//ͷ�巨����˫������
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
        {//�����һ���ڵ�ʱ������������һ��
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

//��ȡ�������һ���ڵ�
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

//�ڵ�i��λ�ò���Ԫ��e
void InsertElem(DuLinklist* L, int i, int e) 
{
    if (i <= (*L)->data) 
    {
        DuLinklist p, r;
        r = (*L);//ָ��ͷ�ڵ��ͷ�ڵ�
        p = (DuLNode*)malloc(sizeof(DuLNode));//ΪҪ�����Ԫ������ռ�
        p->data = e;
        int j = 0;
        for (j = 0; j < i; j++) 
        {//ͨ���������ҵ�Ҫ�����Ԫ��λ��,��ǰr��λ��
            r = r->next;
        }
        if (r->next != NULL) 
        {//�ڵ�����нڵ��ʱ��
            p->next = r->next;
            r->next->prior = p;
            r->next = p;
            p->prior = r;

        }
        else 
        {//�ڵ����û�нڵ���������������Ԫ��
            r->next = p;
            p->prior = r;
            p->next = NULL;
        }
    }
    else 
    {
        printf("�����±겻��������������\n");
    }
}

//��β������ڵ���
void InsertTailNode(DuLinklist* L, int* dat, int num)
{
    int i;
    DuLinklist p, r;
    for (i = 0; i < num; i++)
    {
        r = GetLast(L);//ָ��β�ڵ�
        p = (DuLNode*)malloc(sizeof(DuLNode));//ΪҪ�����Ԫ������ռ�
        p->data = dat[i];
        r->next = p;
        p->prior = r;
        p->next = NULL;
    }
}

//��ͷ��������ڵ���
void InsertHeadNode(DuLinklist* L, int* dat, int num)
{
    int i;
    DuLinklist p, r;
    r = (*L);//ָ��ͷ�ڵ�
    for (i = 0; i < num; i++)
    {
        p = (DuLNode*)malloc(sizeof(DuLNode));//ΪҪ�����Ԫ������ռ�
        p->data = dat[i];
        p->next = r->next;
        p->prior = r;
        r->next = p;
        r = r->next;
    }
}

//��ȡ������
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

//ɾ����i��λ�õ�Ԫ��
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
        {//��������һ���ڵ�
            r = p->next;//Ҫɾ�����±�
            p->next = NULL;
            free(r);//�ͷŸýڵ���ڴ�
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
        printf("�±����\n");
    }
}

//ɾ�����������ڵ�
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
        printf("ɾ���ڵ���Ŀ����ʵ�ʽڵ���Ŀ\n");
    }

}

//��ȡ��i��Ԫ��
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
        printf("\n��%d��Ԫ��:%d\n", i, elem);
        return elem;
    }
    else 
    {
        printf("error\n");
        return FALSE;
    }
}

//��ȡ�ýڵ��ֵ��ɾ��
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


//˳���������
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

//�������������β��������ͷ��������prior�ڵ�
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