#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int sum = 0, i = n;
    while(i > 0)
    {
        sum += i;
        i--;
    }
    i = n;
    int a[100][100] = {0};
    a[0][0] = 1;
    for(int j = 1; j < n; j++)
    {
        a[j][0] = a[j-1][0]+j;
    }
    for(int t = 1; t < n; t++)
    {
        for(int k = t; k > 0; k--)
        {
            for(int p = 0; p < t; p++)
            {
                a[k-1][p+1] = a[k][p]+1;
            }
        }
    }
    if(i > 0)
    {
        for(int x = 0; x < n; x++)
        {
            for(int y = 0; y < i; y++)
            cout << a[x][y] << " ";
            cout << endl;
            i--;
        }
    }
    return 0 ;
}