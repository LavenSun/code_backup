#if 0
//const关键字修饰类
//1、修饰数据成员、成员函数、类对象
//2、修饰数据成员时，初始化只能在参数列表里
//3、修饰成员函数时，const放在声明之后、实现体之前；
//函数不会修改数据成员，只能访问const和非const数据成员，但不能修改非const数据成员，只能访问const成员函数
//const对象只能调用const成员函数；非const对象优先调用非const成员函数，然后才是const成员函数
//4、修饰类对象时，只能调用const成员函数
//5、const修饰函数要求在声明和定义处均有const,其他关键字不一定
//6、在C语言中，static修饰全局（外延性，仅用于本文件）和局部变量
//7、static在类内部的表现，用来实现族类对象间的数据共享
//8、生成对象时，普通数据成员才有空间；static成员在类声明时已开辟空间
//9、static修饰成员函数，用于管理static成员
//10、static修饰的成员函数属于类，没有this指针，不能访问非static的数据成员和成员函数
#include<iostream>
using namespace std;
class A
{
public:
	A(int v = 0)
		:val(v)
	{
		x = 20;
	}
	void display() const
	{
		cout << val << endl;
		//x = 100;会报错
	}
	void display()
	{
		cout << val << endl;
	}
private:
	const int val;
	int x;
};
class B
{
public:
	void fun()
	{
		cout << share << endl;
	}
	void modify(int m)
	{
		share = m;
	}
private:
	int x, y;
	static int share;
};
int B::share = 0;
class school
{
public:
	string& Tower()
	{
		return tower;
	}
	static string& Lib()
	{
		return library;
	}
private:
	string lake;
	string tower;
	static string library;
};
string school::library = "";
class NewList
{
public:
	NewList(int d)
	{
		data = d;
		this->next = head;
		head = this;
	}
	static void check()
	{
		NewList* p = head;
		while (p)
		{
			cout << p->data << endl;
			p = p->next;
		}
	}
private:
	int data;
	NewList* next;
	static NewList* head;
};
NewList* NewList::head = NULL;
class C
{
public:
	void display1()
	{
		cout << x << endl;
	}
private:
	static const int x = 10;
};
int main()
{
	A example1(10);
	example1.display();
	const A example2(100);
	example2.display();
	B a, b;
	cout << sizeof(B) << endl << sizeof(a) << endl;
	a.fun();
	a.modify(1000);
	b.fun();
	school Peking, Tinghua;
	Peking.Tower() = "weiming";
	Tinghua.Tower() = "none";
	Peking.Lib() += "math";
	Tinghua.Lib() += "+English";
	cout << Peking.Lib() << endl;
	NewList a1(1), b1(2), c1(3);
	for (int i = 10; i < 16; i++)
		new NewList(i);
	NewList::check();
 	return 0;
}
#endif