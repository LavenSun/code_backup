#if 0,
//��ʵ��string�࿽���������͸�ֵ���������
#include<iostream>
#include<string.h>
#include"CopyString.h"
using namespace std;
class Stu
{
public:
	Stu(string name, int age) 
	{
		//����Ĳ����������˽�г�Ա��Ӧ��ʹ��ͬ�������֣�ʹ��thisָ����Ա�����������µ��쳣
		this->name = name;
		this->age = age;
	}
	//��������д������ȫ
	//Stu(string n, int a)
	//{
	//	//����Ĳ����������˽�г�Ա��Ӧ��ʹ��ͬ�������֣�ʹ��thisָ����Ա�����������µ��쳣
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
	string s5 = s3; //����Ҳ�ǿ������죨��һ�����еĶ��������һ��������޵��еĴ������̣�
	cout << s3 << endl;
	cout << s5 << endl;
	cout << "-----------------" << endl;
	CopyString s2("Canada");
	CopyString s4(s2); //�˴����ܻ����
	CopyString s6 = s2; //Ĭ��
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
//����ͨ������˵��������Ч�������ԣ������������Դ�����Ч�ʸ���
//�������൱������ԭ�������������ò�ռ���µ��ڴ�ռ�
//ջ�ϵĶ���ɷ��أ�ջ�ϵ����ò��ܷ��أ����Ƿ��ض�����
#endif