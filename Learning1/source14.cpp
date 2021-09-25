#if 0
#include<iostream>
#include<stdlib.h>
#include<memory>
using namespace std;
class A
{
public:
	A()
	{
		cout << "A()" << endl;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
	void func()
	{
		cout << "func()" << endl;
	}
};
class smt
{
public:
	smt(A* p)
	{
		ptr = p;
	}
	~smt()
	{
		delete ptr;
	}
	A* operator->()
	{
		return ptr;
	}
	A& operator*()
	{
		return *ptr;
	}
private:
	A* ptr;

};
void f()
{
	//A* p = new A;
	//delete p;
	auto_ptr<A> ptr(new A);
	ptr->func();//无需delete，ptr在离开其栈空间时delete
	(*ptr).func();
	smt s(new A);
	s->func();
	(*s).func();
}
int main()
{
	f();
	return 0;
}
#endif