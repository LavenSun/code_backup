#if 0
#include<iostream>
#include<string.h>
#include"NewString.h"
using namespace std;
//���������ʾ��
struct Complex
{
	int real;
	int image;
};
Complex operator+(Complex x, Complex y)
{
	Complex CalculateResult;
	CalculateResult.real = x.real + y.real;
	CalculateResult.image = x.image + y.image;
	return CalculateResult;
}
int main()
{
	//���������ʾ��
	Complex i = {2, 3}, j = {5, 6};
	Complex Result = i + j;
	cout << "Result = " << Result.real << "+" << Result.image << "j" << endl;
	//����������ϰ
	string s1, s2("abcdefg"); //char* _str = ""
	cout << s1 << s2 << endl;
	string* ps = new string("haha");
	cout << (*ps).c_str() << endl;
	delete ps;
	const char* p = ""; //char* p = ""�ᱨ��
	cout << "====" << p << "-----" << endl;
	NewString mys1, mys2("china");
	//�ȹ���ĺ�����
	NewString* mys3 = new NewString("hehe");
	cout << (*mys3).c_str() << endl;
	delete mys3;
	cout << mys1.c_str() << endl << mys2.c_str() << endl;

	return 0;
}
#endif