#include "NewStudent.h"
void NewStudent::dis()
{
	cout << "My name is " << name << ", I am " << age << " years old" << endl;
}
NewStudent::NewStudent(const NewStudent& another)
{
	this->age = another.age;
	this->name = another.name;
	this->score = another.score;
}
//NewStudent& NewStudent::operator=(const NewStudent& another){}
ostream& operator<<(ostream& out, NewStudent& stu)
{
	return out << stu.age << "----" << stu.name << stu.score << endl;
}