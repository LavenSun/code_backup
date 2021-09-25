#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "uthash.h"

// 基本的uthash操作

typedef struct // key类型为int
{
    int key;
    char val[10];
    UT_hash_handle hh;
} hash1;

hash1 *g_users = NULL;

hash1 *find_user(int ikey)
{
    hash1 *h1;
    HASH_FIND_INT(g_users, &ikey, h1);
    return h1;
}

void add_user(int ikey, char *c_val)
{
    hash1 *h1;
    HASH_FIND_INT(g_users, &ikey, h1);
    if (h1 == NULL)
    {
        h1 = (hash1 *)malloc(sizeof(hash1));
        h1->key = ikey;
        HASH_ADD_INT(g_users, ikey, h1);
    }
    strcpy(h1->val, c_val);
}

void delete_user(int ikey)
{
    hash1 *h1 = NULL;
    HASH_FIND_INT(g_users, &ikey, h1);
    if (h1 != NULL)
    {
        HASH_DEL(g_users, h1);
        free(h1);
    }
}

void delete_all()
{
    hash1 *cur, *tmp;
    HASH_ITER(hh, g_users, cur, tmp)
    {
        HASH_DEL(g_users, cur);
        free(cur);
    }
}

// HASH_CLEAR(hh, g_users); // 只删除而没有释放内存

unsigned int num = HASH_COUNT(g_users);

void read_all()
{
    hash1 *cur, *tmp;
    HASH_ITER(hh, g_users, cur, tmp)
    {
        printf("%d, %s", cur->key, cur->val);
    }
    /*
    for(hash1 *h1 = g_users, h1 != NULL; h1 = (hash1*)(h1->hh.next))
    {
        printf("%d, %s", cur->key, cur->val);
    }
    */
}

int name_sort(hash1 *h1, hash1 *h2)
{
    return strcmp(h1->val, h2->val);
}

int key_sort(hash1 *h1, hash1 *h2)
{
    return h1->key - h2->key;
}

void sort_by_name()
{
    HASH_SORT(g_users, name_sort);
}

void sort_by_key()
{
    HASH_SORT(g_users, id_sort);
}

typedef struct
{
    const char *c;
    int id;
    UT_hash_handle hh;
} hash2;

void use_hash2()
{
    const char **c1, *names[] = {"joe", "bob", "barry", NULL};
    hash2 *h2, *tmp, *users = NULL;
    int i = 0;
    for (c1 = names; *c1 != NULL; c1++)
    {
        h2 = (hash2 *)malloc(sizeof(hash2));
        h2->c = *c1;
        h2->id = i++;
        HASH_ADD_KEYPTR(hh, users, h2->c, strlen(h2->c), h2);
    }
    HASH_FIND_STR(users, "bob", h2);
    if (h2 != NULL)
    {
        printf("job's id is %d\n", h2->id);
    }
    HASH_ITER(hh, users, h2, tmp)
    {
        HASH_DEL(users, h2);
        free(h2);
    }
    return;
}

int main()
{
    return 0;
}