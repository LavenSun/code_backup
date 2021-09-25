#include<iostream>
#include "NewStudent.h"
#include "Graduate.h"
#include "Doctor.h"
using namespace std;
int main()
{
	NewStudent s1("Bob", 15, 90);
	s1.dis();
	Graduate s2("John", 24, 90, 2000);
	s2.print();
	Graduate s3(s2);
	s3.print();
	Graduate s4 = s3;
	s4.print();
	return 0;
}