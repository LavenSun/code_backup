#pragma once
#include<iostream>
using namespace std;
class NewStudent
{
public:
	NewStudent(string sn, int ia, float fs)
		:name(sn), age(ia), score(fs) {}
	void dis();
	NewStudent(const NewStudent& another);
	//NewStudent& operator=(const NewStudent& another);
	friend ostream& operator<<(ostream& out, NewStudent& stu);
private:
	string name;
	int age;
	float score;
};

