#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "my_map.h"

hashList *HashListInit()
{
    hashList *p = (hashList *)malloc(sizeof(hashList));
    p->val = 0;
    p->str = "hello world";
    p->next = NULL;
    return p;
}

void add(hashList *p, int newVal, char *newStr)
{
    hashList *tmp = (hashList *)malloc(sizeof(hashList));
    if (tmp == NULL)
    {
        printf("hashList malloc error!\n");
        return;
    }
    tmp->val = newVal;
    tmp->str = newStr;
    tmp->next = NULL;
    p->next = tmp;
    return;
}

hashList *search(hashList *p, int val, char *str)
{
    while (p != NULL)
    {
        if (p->val == val && strcmp(p->str, str) == 0)
            return p;
        p = p->next;
    }

    return NULL;
}