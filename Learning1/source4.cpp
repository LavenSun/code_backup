#if 0,
//自实现string类拷贝构造器和赋值运算符重载
#include<iostream>
#include<string.h>
#include"CopyString.h"
using namespace std;
class Stu
{
public:
	Stu(string name, int age) 
	{
		//传入的参数名和类的私有成员不应该使用同样的名字，使用this指针可以避免这种情况下的异常
		this->name = name;
		this->age = age;
	}
	//采用如下写法更安全
	//Stu(string n, int a)
	//{
	//	//传入的参数名和类的私有成员不应该使用同样的名字，使用this指针可以避免这种情况下的异常
	//	name = n;
	//	age = a;
	//}
	void display()
	{
		cout << "this = " << this << endl;
		cout << name << "-----" << age << endl;
	}
	Stu* GrowUp()
	{
		this->age++;
		return this;
	}
private:
	string name;
	int age;
};
int main()
{
	string s1("china");
	cout << s1 << endl;
	string s3(s1);
	string s5 = s3; //本质也是拷贝构造（由一个已有的对象，完成另一个对象从无到有的创建过程）
	cout << s3 << endl;
	cout << s5 << endl;
	cout << "-----------------" << endl;
	CopyString s2("Canada");
	CopyString s4(s2); //此处可能会崩溃
	CopyString s6 = s2; //默认
	CopyString s8, s10;
	s10 = s8 = s6;
	cout << s2.c_str() << endl;
	cout << s4.c_str() << endl;
	cout << s6.c_str() << endl;
	cout << s8.c_str() << endl;
	cout << s10.c_str() << endl;
	Stu S("bob", 16);
	cout << "&S = " << &S << endl;
	S.display();
	S.GrowUp()->GrowUp()->display();
	return 0;
}
//对普通变量来说，传引用效果不明显；对于类对象而言传对象效率更高
//传引用相当于扩大原对象作用域，引用不占用新的内存空间
//栈上的对象可返回，栈上的引用不能返回（除非返回对象本身）
#endif