#include <stdio.h>

typedef struct tagHashList
{
    int val;
    char *str;
    struct tagHashList *next;
} hashList;

hashList *HashListInit();
void add(hashList *p, int newVal, char *newStr);
hashList *search(hashList *p, int val, char *str);