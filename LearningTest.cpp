#include<iostream>
using namespace std;
void print(int a)
{
    cout << "void print(int a): " << a << endl;
}
void print(char b[])
{
    cout << "void print(char b): " << b << endl;
}
int main()
{
    int a = 10;
    char b[30] = "chain reaction";
    print(a);
    print(b);
    return 0;
}