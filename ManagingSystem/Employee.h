#pragma once
#include<iostream>
using namespace std;
class Employee
{
public:
	Employee();
	virtual void calSalary() = 0;
	virtual void disInfo() = 0;
	virtual void promote() = 0;
protected:
	string name;
	int grade;
	int num;
	float salary;
	static int startNum;
};

