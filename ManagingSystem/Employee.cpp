#include "Employee.h"
int Employee::startNum = 100;
Employee::Employee()
{
	cout << "Please input the names of employees: ";
	cin >> name;
	grade = 1;
	num = startNum++;
}