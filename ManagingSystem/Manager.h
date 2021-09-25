#pragma once
#include"Employee.h"
class Manager
	:virtual public Employee
{
public:
	Manager();
	virtual void calSalary();
	virtual void disInfo();
	virtual void promote();
protected:
	float fixSalary;
};

