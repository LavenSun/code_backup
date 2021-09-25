#if 0
//∂—ƒ⁄¥Ê‘ÀÀ„∑˚÷ÿ‘ÿ
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
void* operator new(size_t size)
{
	void* p = malloc(size);
	memset(p, 0, size);
	return p;
}
void operator delete(void* p)
{
	free(p);
}
void* operator new[](size_t size)
{
	void* p = (void*)malloc(size);
	//memset(p, 0, size);
	return p;
}
void operator delete[](void* p)
{
	free(p);
}
int main()
{
	return 0;
}
#endif