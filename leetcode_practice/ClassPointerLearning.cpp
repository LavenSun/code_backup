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
	return 0;
}