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
	char* c_str(); //�˴�ʹ���˺�������
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
	A(int i = 0) //�����б�Ч�ʸ�
		:x(i), y(i + 1), z(i + 2)
	{

	}
	~A(){}
private:
	int x; 
	int y;
	int z;
};
�������ص㣺
1��������ͬ���޷��أ������ɶ���ջ���ѣ�ʱ�Զ������ã����ڳ�ʼ��
2��ϵͳ�ṩĬ���޲εĹ������������в����������ػ�Ĭ�ϲ��������ػ�Ĭ�Ͽ�ʵ���޲ε������һ�����Ĭ��
3��һ���ṩ�Զ��幹������ϵͳĬ�ϵĹ��������ٴ���
�����б��ں�������֮��ʵ����֮ǰ
�������ص㣺
1��������ͬ���޷��أ��޲Ρ��ڶ�������֮ǰ������
2��ջ�����뿪�����򡢶Ѷ���deleteʱ����������
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
