#if 0
#include<iostream>
#include<string.h>
using namespace std;
class stu
{
public:
	stu(string na)
		//参数列表初始化顺序和变量声明顺序有关，和初始化表中的顺序无关
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