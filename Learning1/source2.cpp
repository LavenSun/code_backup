#if 0
#include<iostream>
#include<string.h>
using namespace std;
class stu
{
public:
	stu(string na)
		//�����б��ʼ��˳��ͱ�������˳���йأ��ͳ�ʼ�����е�˳���޹�
		:name(na), len(strlen(name.c_str()))
	{
		//name = na;
		//len = strlen(name.c_str());
	}
	void dis()
	{
		cout << len << endl;
	}
private:
	string name;
	int len;
};
int main()
{
	stu s("china");
	s.dis();
	return 0;
}
#endif