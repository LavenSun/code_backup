#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LEN 1000

int main()
{
    char maxStr[MAX_LEN], tmpStr[MAX_LEN];
    int count, num = -1;
    char ch;
    while((ch = getchar()) != EOF && ch != '\n')
    {
        //ch = getchar();
        //tmpStr[0] = ch;
        gets(tmpStr);
        //gets函数无法读入第一个字符？？？
        count = strlen(tmpStr);
        if(count > num)
        {
            num = count;
            strcpy(maxStr, tmpStr);
            maxStr[num] = '\0'; 
        }
    }
    printf("%s", maxStr);
    return 0;
}