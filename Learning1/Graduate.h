#pragma once
#include "NewStudent.h"
class Graduate :
    public NewStudent
{
public:
    Graduate(string sn, int ia, float fs, float ds);
    void print();
    Graduate(const Graduate& another);
    Graduate& operator=(const Graduate& another);
private:
    float salary;
};

