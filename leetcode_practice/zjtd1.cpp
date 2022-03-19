#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[10000];
    for(int i = 0; i < n; i++)
    cin >> a[i];
    int m;
    cin >> m;
    int b[10000][3]; //b[m][3]
    for (int j = 0; j < m; j++)
    {
        for (int k = 0; k < 3; k++)
            cin >> b[j][k];
    }
    int Count[10000] = {0};
    for(int l = 0; l < m; l++)
    {
        for(int x = b[l][0]-1; x < b[l][1]; x++)
        {
            if(a[x] == b[l][2])
            Count[l]++;
        }
    }
    for(int t = 0; t < m; t++)
    cout << Count[t] << endl;
    return 0;
}