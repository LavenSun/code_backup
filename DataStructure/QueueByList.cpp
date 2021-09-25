#include<stdio.h>
#include<stdlib.h>
#include"Function.h"

//���е���ʽ��ʾ
void init_linkqueue(link_pqueue* Q)     //��������
{
	//����front��rear�Ŀռ�
	*Q = (link_pqueue)malloc(sizeof(link_queue));
	if ((*Q) == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	//����ͷ���ռ�
	(*Q)->front = (linkqueue_pnode)malloc(sizeof(linkqueue_node));
	if ((*Q)->front == NULL)
	{
		perror("malloc");
		exit(-1);
	}

	(*Q)->front->next = NULL;
	(*Q)->rear = (*Q)->front;

	return;
}

//���
bool in_linkqueue(datatype data, link_pqueue q)
{
	linkqueue_pnode  newNode;

	//�������ݽ��ռ�
	newNode = (linkqueue_pnode)malloc(sizeof(linkqueue_node));
	if (newNode == NULL)
	{
		puts("���ʧ�ܣ�");
		return false;
	}
	//�����ݴ洢������Ŀռ�
	newNode->data = data;

	//��newָ��Ľ����뵽��ʽ������
	newNode->next = q->rear->next;            //����ȼ���new->next = NULL;
	q->rear->next = newNode;

	//��rearָ��ָ���µĶ�β���
	q->rear = q->rear->next;          //�ȼ���q->rear = new;

	return true;
}

bool is_empty_linkqueue(link_pqueue q)          //�ж϶����Ƿ�Ϊ��
{
	if (q->rear == q->front)
		return true;
	else
		return false;
}

//����
bool out_linkqueue(link_pqueue q, datatype* D)
{
	linkqueue_pnode t;
	//�ж϶����Ƿ��
	if (is_empty_linkqueue(q)) {
		printf("�����ѿ�!\n");
		return false;
	}

	//����
	t = q->front;
	q->front = q->front->next;
	*D = q->front->data;
	free(t);

	return true;
}

void show_linkqueue(link_pqueue q)          //���δ�ӡ��ͷ����β������
{
	linkqueue_pnode p;
	if (is_empty_linkqueue(q))
		return;
	//�ǿ�ʱ���Ӷ�ͷ��ӡ����β
	for (p = q->front->next; p != NULL; p = p->next)
	{
		printf("%d\t", p->data);
	}
	printf("\n");
}

void free_linkqueue(link_pqueue q)           //�ͷŶ���
{
	linkqueue_pnode p;
	p = q->front;
	while (p)
	{
		q->front = q->front->next;
		free(p);
		p = q->front;
	}
	free(q);
}