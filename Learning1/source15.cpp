#if 0
#include<iostream>
using namespace std;
class Man
{
public:
	void eat(string food)
	{
		cout << "I eat things" << endl;
	}
};
class Student :public Man
{
public:
	void learn(string course)
	{
		cout << "I learn things" << endl;
	}
};
class Teacher :public Man
{
public:
	void teach(string course)
	{
		cout << "I teach things" << endl;
	}
};
int main()
{
	return 0;
}
#endif