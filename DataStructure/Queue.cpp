#include<stdio.h>
#include<stdlib.h>
#include"Function.h"

sp_queue queue_init()
{
    sp_queue q;
    q.front = q.rear = 0;
    return q;
}

int queue_empty(sp_queue q)
{
    return q.front == q.rear;
}

int queue_en(sp_queue* q, datatype e)
{
    /* ���� */
    if (q->rear == MAX_QUEUE_SIZE)
        return false;

    /* ��� */
    q->sp_queue_array[q->rear] = e;
    printf("q.sp_queue_array[%d]=%d\n", q->rear, e);
    q->rear += 1;
    return true;
}

int queue_de(sp_queue* q, datatype* e)
{
    /* �ӿ� */
    if (queue_empty(*q))
        return false;

    /* ���� */
    q->rear -= 1;
    *e = q->sp_queue_array[q->rear];
    return true;
}

void queue_clear(sp_queue* q)
{
    q->front = q->rear = 0;
}

int get_front(sp_queue q, datatype* e)
{
    /* �ӿ� */
    if (q.front == q.rear)
        return false;

    /* ��ȡ��ͷԪ�� */
    *e = q.sp_queue_array[q.front];
    return true;
}

int queue_len(sp_queue q)
{
    return (q.rear - q.front);
}

void visit(sp_queue q)
{
    /* �ӿ� */
    if (q.front == q.rear)
        printf("����Ϊ��\n");

    int temp = q.front;
    while (temp != q.rear)
    {
        printf("%d ", q.sp_queue_array[temp]);
        temp += 1;
    }
    printf("\n");
}

void queue_traverse(sp_queue q, void (*visit)(sp_queue q))
{
    visit(q);
}

void UseQueue1()
{
    sp_queue q = queue_init();
    queue_en(&q, 1);
    queue_en(&q, 2);
    printf("length=%d\n", queue_len(q));
    queue_en(&q, 3);
    printf("length=%d\n", queue_len(q));
    queue_en(&q, 4);
    printf("length=%d\n", queue_len(q));
    queue_en(&q, 5);
    printf("length=%d\n", queue_len(q));
    queue_en(&q, 6);
    printf("length=%d\n", queue_len(q));
    queue_traverse(q, visit);
    datatype* e = (datatype*)malloc(sizeof(*e));
    queue_de(&q, e);
    printf("queue_de(),e=%d length=%d\n", *e, queue_len(q));
    queue_traverse(q, visit);
    queue_clear(&q);
    queue_traverse(q, visit);
    printf("length:%d\n", queue_len(q));
    return;
}

