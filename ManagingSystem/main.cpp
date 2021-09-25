#include<iostream>
#include"Technician.h"
#include"Manager.h"
#include"Salesman.h"
using namespace std;
int main()
{
	//Technician t1;
	//t1.calSalary();
	//t1.promote();
	//t1.disInfo();
	//Manager m1;
	//m1.calSalary();
	//m1.promote();
	//m1.disInfo();
	//Salesman s1;
	Employee* emp[] = { new Technician, new Manager, new Salesman };
	for (int i = 0; i < (sizeof(emp) / sizeof(emp[0])); i++)
	{
		emp[i]->calSalary();
		emp[i]->promote();
		emp[i]->disInfo();
	}
	return 0;
}