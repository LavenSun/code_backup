#if 0
//const�ؼ���������
//1���������ݳ�Ա����Ա�����������
//2���������ݳ�Աʱ����ʼ��ֻ���ڲ����б���
//3�����γ�Ա����ʱ��const��������֮��ʵ����֮ǰ��
//���������޸����ݳ�Ա��ֻ�ܷ���const�ͷ�const���ݳ�Ա���������޸ķ�const���ݳ�Ա��ֻ�ܷ���const��Ա����
//const����ֻ�ܵ���const��Ա��������const�������ȵ��÷�const��Ա������Ȼ�����const��Ա����
//4�����������ʱ��ֻ�ܵ���const��Ա����
//5��const���κ���Ҫ���������Ͷ��崦����const,�����ؼ��ֲ�һ��
//6����C�����У�static����ȫ�֣������ԣ������ڱ��ļ����;ֲ�����
//7��static�����ڲ��ı��֣�����ʵ��������������ݹ���
//8�����ɶ���ʱ����ͨ���ݳ�Ա���пռ䣻static��Ա��������ʱ�ѿ��ٿռ�
//9��static���γ�Ա���������ڹ���static��Ա
//10��static���εĳ�Ա���������࣬û��thisָ�룬���ܷ��ʷ�static�����ݳ�Ա�ͳ�Ա����
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
		//x = 100;�ᱨ��
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