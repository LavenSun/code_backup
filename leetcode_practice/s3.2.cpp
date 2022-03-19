#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    long long sum1 = 0, sum2 = 0;
    for(int i = 1; i < n+1; i++)
    sum1 += n/i;
    int i = 1;
        while(i < sqrt(n))
        {
            sum2 += n/i;
            i++;
        }
        int mid = n/2;
        if(mid > i)
        {
            i = mid-i;
            sum2 += i;
        }
        sum2 += (n-i+1);
    cout << sum1 << endl << sum2;
    return 0;
}