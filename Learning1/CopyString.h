#pragma once
#include <cstddef>
class CopyString
{
public:
	CopyString(const char* p = NULL); //默认参数只能在声明中
	~CopyString();
	CopyString(const CopyString& another); //拷贝构造器，浅拷贝；深拷贝需要自己实现
	//系统有默认拷贝构造器，一旦自己写，默认的失效
	CopyString& operator=(const CopyString& another);
	CopyString operator+(const CopyString& another);
	bool operator>(const CopyString& another);
	bool operator<(const CopyString& another);
	bool operator==(const CopyString& another);
	char& operator[](int index);
	char at(int index);
	//默认运算符重载也是一种等位赋值，浅赋值(可能导致内存泄漏、重复析构、自赋值）
	char* c_str();
private:
	char* _str;
};

