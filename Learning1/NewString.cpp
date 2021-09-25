#include "NewString.h"
#include<string.h>
#pragma warning(suppress : 4996)
//NewString::NewString()
//{
//	_str = new char[1];
//	*_str = '\0';
//}
NewString::NewString(const char* s)
{
	if(s == NULL)
	{
		_str = new char[1];
		*_str = '\0';
	}
	else
	{
		int len = strlen(s);
	_str = new char[len + 1];
	strcpy(_str, s); //VS2019编译器认为strcpy不安全，已禁用该警告
	}
}
char* NewString::c_str()
{
	return _str;
}
NewString::~NewString()
{
	delete[]_str;
}