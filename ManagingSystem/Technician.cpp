#include "Technician.h"
Technician::Technician()
{
	cout << "Please input the working hour of technicians: ";
	cin >> hourAmount;
	moneyPerHour = 100;
}
void Technician::calSalary()
{
	salary = hourAmount * moneyPerHour;
}
void Technician::disInfo()
{
	cout << "name: " << name << endl;
	cout << "number: " << num << endl;
	cout << "ranking: " << grade << endl;
	cout << "salary: " << salary << endl;
}
void Technician::promote()
{
	grade = 3;
}