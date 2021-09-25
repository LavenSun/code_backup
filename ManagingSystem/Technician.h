#pragma once
#include "Employee.h"
class Technician :
    public Employee
{
public:
    Technician();
    virtual void calSalary();
    virtual void disInfo();
    virtual void promote();
protected:
    int hourAmount;
    int moneyPerHour;
};

