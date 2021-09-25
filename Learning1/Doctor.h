#pragma once
#include "Graduate.h"
class Doctor :
    public Graduate
{
public:
    Doctor(string sn, int ia, float fs, float ds, string st);
    void dis2()
    {
        print();
    }
private:
    string title;
};

