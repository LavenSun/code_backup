#pragma once
#include<iostream>
#include <cstddef>
using namespace std;
class NewString
{
public:
	//NewString();
	//NewString(){}
	//~NewString(){}
	NewString(const char* s = NULL);
	char* c_str(); //此处使用了函数重载
	~NewString();
private:
	char* _str;
};
#if 0
class Data
{

};
class List
{

};
class stack
{

};
#endif
#if 0
class A
{
public:
	A(){}
	A(int i = 0)
	{
		cout << "begin" << endl;
		x = 1+i;
		y = 2;
		z = 3;
	}
	A(int i = 0) //参数列表，效率高
		:x(i), y(i + 1), z(i + 2)
	{

	}
	~A(){}
private:
	int x; 
	int y;
	int z;
};
构造器特点：
1、与类名同，无返回，在生成对象（栈、堆）时自动被调用，用于初始化
2、系统提供默认无参的构造器，可以有参数、被重载或默认参数；重载或默认可实现无参的情况，一般采用默认
3、一旦提供自定义构造器，系统默认的构造器不再存在
参数列表在函数声明之后、实现体之前
析构器特点：
1、与类名同，无返回，无参。在对象销毁之前被调用
2、栈对象离开作用域、堆对象被delete时调用析构器
#endif
#if 0
class man
{
public:
	man()
	{
		name = new char[100]; //(char*)malloc(100);
	}
private:
	char *name;
	int age;
};
#endif
