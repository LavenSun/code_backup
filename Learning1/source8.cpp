#if 0
//指向类成员的指针
#include<iostream>
using namespace std;
class Stu
{
public:
	Stu(string sn, int ia)
		:name(sn), age(ia){}
	void display()
	{
		cout << name << "---" << age << endl;
	}
	string name;
	int age;
};
class widget
{
public:
	widget()
	{
		pa[0] = &widget::f1;
		pa[1] = &widget::f2;
		pa[2] = &widget::f3;
		pa[3] = &widget::f4;
	}
	void select(int index)
	{
		(this->*pa[index])();
	}
private:
	void f1() { cout << "f1" << endl; }
	void f2() { cout << "f2" << endl; }
	void f3() { cout << "f3" << endl; }
	void f4() { cout << "f4" << endl; }
	//const int cnt = 4;
	enum{cnt = 4};
	void (widget::* pa[cnt])() = { &widget::f1, &widget::f2, &widget::f3, &widget::f4 };
};
int main()
{
	Stu s1("zhaosi", 39);
	Stu s2("aobama", 79);
	Stu *p3 = new Stu("bob", 20);
	int Stu::*p2 = &Stu::age;
	cout << s1.*p2 << "---" << s2.*p2 << endl; //.*是C++的一个新的运算符
	void (Stu:: * pf)() = &Stu::display;
	(s1.*pf)();
	cout << p3->*p2 << endl;
	(p3->*pf)();
	widget example;
	example.select(1);
	return 0;
}
#endif