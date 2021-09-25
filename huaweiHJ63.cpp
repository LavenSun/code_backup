#include<iostream>
#include<string>
using namespace std;

int main()
{
    int n;
    string a;
    cin >> a >> n;
    int m = a.size(), r=0, Count=0, l, t;
    if(n >= m)
    cout << a;
    else
    {
        for(int i = 0; i < m-n-1; i++)
        {
            if(a[i]=='C' || a[i]=='G')
            {
                for(int j = i; j < i+n; j++)
                {
                    if(a[j]=='C' || a[j]=='G')
                    {
                        r++;
                        l = j;
                    }
                }
            }
            if(Count < r)
            {
                Count = r;
                t = l;
            }
            r = 0;
        }   
        if(t-n+1 <= 0)
        {
            for(int y = 0; y < t+4; y++)
            cout << a[y];
        }
        else
        {
            for(int k = t-n+1; k < t+1; k++)
            cout << a[k];
        }
    }
    return 0;
}