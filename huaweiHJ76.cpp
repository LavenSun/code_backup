#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int i = n*n-n+1;
    for(int j = 0; j < n-1; ++j)
    {
        cout << i << "+";
        i = i+2;
    }
    cout << i << endl;
    return 0;
}
