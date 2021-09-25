#pragma once
#include "Employee.h"
class Salesman 
    :virtual public Employee
{
public:
    Salesman();
    virtual void calSalary();
    virtual void disInfo();
    virtual void promote();
protected:
    float monthSaleAmount;
    float rate;
};

