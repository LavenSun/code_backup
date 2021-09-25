#include<iostream>
#include<string>
using namespace std;

int main()
{
    string a;
    cin >> a;
    int n = a.length();
    int Count = 0;
    int x = 0, y = 0, x1 = 0, y1 = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] >= '0' && a[i] <= '9')
        {
            x = i;
            y = i+1;
            while(a[y] >= '0' && a[y] <= '9' && y < n)
            y++;
            if(y-x > Count)
            Count = y-x;
        }
    }
    for(int t = 0; t < y-Count; t++)
    {
        if(a[t] >= '0' && a[t] <= '9')
        {
            x1 = t;
            y1 = t+1;
            while(a[y1] >= '0' && a[y1] <= '9' && y1 < y-Count)
            y1++;
            if(y1-x1 == Count)
            {
                for(int p = y1-Count; p < y1; p++)
                cout << a[p];
            }
        }
    }
    for(int k = y-Count; k < y; k++)
    cout << a[k];
    cout << ',' << Count << endl;
    return 0;
}