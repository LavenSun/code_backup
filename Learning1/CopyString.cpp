#include "CopyString.h"
#include <string.h>
//自实现string类
CopyString::CopyString(const char* p)
{
	if (p == NULL)
	{
		_str = new char[1];
		*_str = '\0';
	}
	else
	{
		int len = strlen(p);
		_str = new char[len + 1];
		strcpy(_str, p);
	}
}
CopyString::~CopyString()
{
	delete[]_str;
}
char* CopyString::c_str()
{
	return _str;
}
CopyString::CopyString(const CopyString& another)
{
	//浅拷贝会导致内存重复析构
	//在有堆空间的时候，要自实现拷贝构造
	int len = strlen(another._str);
	_str = new char[len + 1];
	strcpy(_str, another._str);
	//memcpy(_str, another._str, len);
}
CopyString& CopyString::operator=(const CopyString& another)
{
	if (this == &another)
		return *this;
	delete[]this->_str;
	int len = strlen(another._str);
	this->_str = new char[len + 1];
	strcpy(this->_str, another._str);
	return *this; //实现连等式
}
CopyString CopyString::operator+(const CopyString& another)
{
	CopyString tmp;
	delete[]tmp._str;
	int len = strlen(this->_str);
	len += strlen(another._str);
	tmp._str = new char[len + 1];
	memset(tmp._str, 0, len + 1);
	strcat(tmp._str, this->_str);
	strcat(tmp._str, another._str);
	return tmp;
}
bool CopyString::operator>(const CopyString& another)
{
	if (this->_str > another._str)
		return true;
	else return false;
}
bool CopyString::operator<(const CopyString& another)
{
	if (this->_str < another._str)
		return true;
	else return false;
}
bool CopyString::operator==(const CopyString& another)
{
	if (this->_str == another._str)
		return true;
	else return false;
}
char& CopyString::operator[](int index)
{
	return this->_str[index];
}
char CopyString::at(int index)
{
	return this->_str[index];
}