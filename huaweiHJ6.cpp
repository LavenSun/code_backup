#include<iostream>
using namespace std;

int main()
{
    long n;
    cin >> n;
    int i = 2, x = 0;
    while(n > 1)
    {
        if(n%i == 0)
        {
            for(int j = 2; j < i; j++)
            {
                if(i%j == 0)
                x = 1;
            }
            if(x == 0)
            {
                cout << i << " ";
                n /= i;
                x = 0;
            }
        }
        else
        i++;
    }
    return 0;
}