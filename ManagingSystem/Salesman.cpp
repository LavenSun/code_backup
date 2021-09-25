#include "Salesman.h"
Salesman::Salesman()
{
	cout << "Please input the amount of this month: " << endl;
	cin >> monthSaleAmount;
	rate = 0.05;
}
void Salesman::calSalary()
{
	salary = monthSaleAmount * rate;
}
void Salesman::disInfo()
{
	cout << "name: " << name << endl;
	cout << "number: " << num << endl;
	cout << "ranking: " << grade << endl;
	cout << "salary: " << salary << endl;
}
void Salesman::promote()
{
	grade = 1;
}