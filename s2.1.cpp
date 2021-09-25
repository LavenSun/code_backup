#include<iostream>
#include<string>
using namespace std;

int main()
{
    string x;
    cin >> x;
    int n = x.size();
    string ans = "";
    int y1 = 0, y2 = n-2;
    while(n/2)
    {
        int n1 = n/2;
        int k = 0;
        for (int i = 2; i < n1 - 1; i++) 
        {
            if (n1 % i == 0)
            k = 1;
        } 
        if(k == 0 && y1 < y2)
        {
            ans = x[y1];
            cout << ans;
            ans = x[y1+1];
            cout << ans;
            y1 += 2;
            n -= 2;
        }
        else
        {
            ans = x[y2];
            cout << ans;
            ans = x[y2+1];
            cout << ans;
            y2 -= 2;
            n -= 2;
        }
    }
    return 0;
}