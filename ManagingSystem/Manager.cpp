#include "Manager.h"
Manager::Manager()
{
	fixSalary = 8000;
}
void Manager::calSalary()
{
	salary = fixSalary;
}
void Manager::disInfo()
{
	cout << "name: " << name << endl;
	cout << "number: " << num << endl;
	cout << "ranking: " << grade << endl;
	cout << "salary: " << salary << endl;
}
void Manager::promote()
{
	grade = 4;
}