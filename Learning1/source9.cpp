#if 0
//сят╙
#include<iostream>
#include<math.h>
using namespace std;
class A;
class B
{
public:
	void show(A& a);
};
class A
{
public:
	A(int y)
		:x(y){}
	friend void display(A &a);
	friend void B::show(A &a);
private:
	int x;
};
void display(A& a)
{
	cout << a.x << endl;
}
void B::show(A& a)
{
	cout << a.x << endl;
}
class point
{
public:
	point(double a, double b)
		:x(a), y(b){}
	friend double getDistance(point& a, point& b);
	friend class PointManagement;
private:
	double x, y;
};
class PointManagement
{
public:
	double getTriDistance(point& a, point& b)
	{
		double dx = a.x - b.x;
		double dy = a.y - b.y;
		return sqrt(dx * dx + dy * dy);
	}
};
double getDistance(point& a, point& b)
{
	double dx = a.x - b.x;
	double dy = a.y - b.y;
	return sqrt(dx*dx + dy*dy);
}
int main()
{
	A a(10);
	display(a);
	B b;
	b.show(a);
	point a1(1, 2), b1(3, 4);
	double dis1 = getDistance(a1, b1);
	PointManagement pm;
	double dis2 = pm.getTriDistance(a1, b1);
	cout << dis1 << endl;
	cout << dis2 << endl;
	return 0;
}
#endif