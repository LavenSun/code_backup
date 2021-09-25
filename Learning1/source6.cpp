#if 0
//类成员函数的存储
#include<iostream>
using namespace std;
class Time 
{
public:
	Time(int h, int m, int s)
		:hour(h), min(m), sec(s)
	{

	}
	void display()
	{
		cout << "this = " << this << endl;
		cout << hour  << "--"<< min << "--" << sec << endl;
	}
	void show(Time* t)
	{
		cout << t->hour << "--" << t->min << "--" << t->sec << endl;
	}
private:
	int hour;
	int min;
	int sec;
};
int main()
{
	Time t1(1, 2, 3), t2(3, 4, 5);
	cout << sizeof(Time) << "--" << sizeof(t1) << endl;
	cout << "&t1 = " << &t1 << endl;
	t1.display();
	t1.show(&t1);
	cout << "&t2 = " << &t2 << endl;
	t2.display();
	t2.show(&t2);
	return 0;
}
#endif