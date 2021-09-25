#include<stdio.h>
#include<stdlib.h>
#include"Function.h"

link* initLink() 
{
    link* p = (link*)malloc(sizeof(link));//创建一个头结点
    link* temp = p;//声明一个指针指向头结点，用于遍历链表
    //生成链表
    for (int i = 1; i < 5; i++) {
        link* a = (link*)malloc(sizeof(link));
        a->elem = i;
        a->next = NULL;
        temp->next = a;
        temp = temp->next;
    }
    return p;
}

int selectElem(link* p, int elem) 
{
    link* t = p;
    int i = 1;
    while (t->next) {
        t = t->next;
        if (t->elem == elem) {
            return i;
        }
        i++;
    }
    return -1;
}

link* amendElem(link* p, int add, int newElem) 
{
    link* temp = p;
    temp = temp->next;//在遍历之前，temp指向首元结点
    //遍历到被删除结点
    for (int i = 1; i < add; i++) {
        temp = temp->next;
    }
    temp->elem = newElem;
    return p;
}

link* insertElem(link* p, int elem, int add) 
{
    link* temp = p;//创建临时结点temp
    //首先找到要插入位置的上一个结点
    for (int i = 1; i < add; i++) 
    {
        if (temp == NULL) 
        {
            printf("插入位置无效\n");
            return p;
        }
        temp = temp->next;
    }
    //创建插入结点c
    link* c = (link*)malloc(sizeof(link));
    c->elem = elem;
    //向链表中插入结点
    c->next = temp->next;
    temp->next = c;
    return  p;
}

link* delElem(link* p, int add) 
{
    link* temp = p;
    //temp指向被删除结点的上一个结点
    for (int i = 1; i < add; i++) 
    {
        temp = temp->next;
    }
    link* del = temp->next;//单独设置一个指针指向被删除结点，以防丢失
    temp->next = temp->next->next;//删除某个结点的方法就是更改前一个结点的指针域
    free(del);//手动释放该结点，防止内存泄漏
    return p;
}

void display(link* p) 
{
    link* temp = p;//将temp指针重新指向头结点
    //只要temp指针指向的结点的next不是Null，就执行输出语句。
    while (temp->next) 
    {
        temp = temp->next;
        printf("%d", temp->elem);
    }
    printf("\n");
}

int UseChainList()
{
    //初始化链表（1，2，3，4）
    printf("初始化链表为：\n");
    link* p = initLink();
    display(p);

    printf("在第4的位置插入元素5：\n");
    p = insertElem(p, 5, 4);
    display(p);

    printf("删除元素3:\n");
    p = delElem(p, 3);
    display(p);

    printf("查找元素2的位置为：\n");
    int address = selectElem(p, 2);
    if (address == -1) {
        printf("没有该元素");
    }
    else {
        printf("元素2的位置为：%d\n", address);
    }
    printf("更改第3的位置的数据为7:\n");
    p = amendElem(p, 3, 7);
    display(p);

    return 0;
}