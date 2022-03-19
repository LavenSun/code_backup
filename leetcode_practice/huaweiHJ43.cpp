#include<iostream>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    int a[10][10];
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        cin >> a[i][j];
    }
    int k = 0, t = 0;
    cout << "(0, 0)" << endl;
    while(k < N && t < M)
    {
        if(k == M-1 && t == N-1)
        break;
        else if(a[k+1][t] == 0 && a[k][t+1] != 0)
        {
            cout << "(" << k+1 << ", " << t << ")" << endl;
            k++;
        }
        else if(a[k+1][t] != 0 && a[k][t+1] == 0)
        {
            cout << "(" << k << ", " << t+1 << ")" << endl;
            t++;
        }
        else if(a[k+1][t] == 0 && a[k][t+1] == 0)
        {
            if(t <= k)
            {
                cout << "(" << k << ", " << t+1 << ")" << endl;
                t++;
            }
            else 
            {
                cout << "(" << k+1 << ", " << t << ")" << endl;
                k++;
            }
        }
    }
    return 0;
}