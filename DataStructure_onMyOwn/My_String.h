#pragma once
#include<stdio.h>

#define MAXSTRLEN 255
typedef unsigned char my_string[MAXSTRLEN + 1]; //my_string[0]=the length of the string

bool Concat(my_string& T, my_string s1, my_string s2);

bool SubString(my_string& sub, my_string s, int pos, int len);

typedef struct
{
	char* ch; //���ַ����ǿ����ַ������ȷ���洢��������ΪNULL
	int length;
}HString; //�ַ����Ķѷ���洢��ʾ

bool StrInsert(HString& s, int pos, HString T);

bool StrAssign(HString& T, char* c);

int StrLength(HString s);

int StrCompare(HString s, HString t);

void ClearStr(HString& s);

bool ConCat(HString& t, HString s1, HString s2);

bool SubStr(HString& t, HString s, int pos, int len);


#define CHUNKSIZE 80
typedef struct Chunk
{
	char ch[CHUNKSIZE];
	struct Chunk* next;
}Chunk;

typedef struct
{
	Chunk* head, * tail;
	int curlen;
}LString;

//���Ӵ�λ�õĶ�λ����
int Index(my_string s, my_string t, int pos);

void getNext(my_string t, int next[]);

void getNextval(my_string t, int next[]);

int Index_KMP(my_string s, my_string t, int pos);
