#include "Graduate.h"
Graduate::Graduate(string sn, int ia, float fs, float ds)
	:NewStudent(sn, ia, fs), salary(ds){}
void Graduate::print()
{
	dis();
}
Graduate::Graduate(const Graduate& another)
	: NewStudent(another), salary(another.salary){}
Graduate& Graduate::operator=(const Graduate& another)
{
	if (this == &another)
		return *this;
	NewStudent::operator = (another);
	this->salary = another.salary;
	return *this;
}