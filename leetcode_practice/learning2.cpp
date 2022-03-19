#include<iostream>
using namespace std;

int main()
{
    int n, num = 1;
    int m = 1;
    while(cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
                 if(!(i / m))
                 {
                    if((i*i - i) % m == 0)
                    num++;
                 }
                 else 
                 m = m*10;
        }
        cout << num << endl;
    }
    return 0;
}