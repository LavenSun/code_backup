#if 0
//对象数组
#include<iostream>
using namespace std;
class Stu
{
public:
	//Stu(string n):_name(n){}; //注意构造器应当包含无参的情况
	Stu(string n = "") :_name(n) {};
	void display()
	{
		cout << _name << endl;
	}
private:
	string _name;
};
int main()
{
	Stu ArrayStr[3] = { Stu("abc"), Stu("def"), Stu("ghi") };
	return 0;
}
#endif