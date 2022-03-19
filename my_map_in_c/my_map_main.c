#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_map.h"

int main()
{
    hashList *head = HashListInit();
    if (head == NULL)
    {
        printf("HashListInit() error!\n");
        return 0;
    }

    int x1 = 1;
    char *str1 = "first element";
    add(head, x1, str1);
    if (head != NULL)
        printf("val = %d, str = %s\n", head->val, head->str);

    return 0;
}