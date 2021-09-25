#include<iostream>
using namespace std;
int main()
{
    int x;
    cin >> x;
    int y = x;
    int i = 0;
        while(y > 0)
        {
            y /= 10;
            i++; 
        }
        int j = 1, t = 10;
        int ans = 0;
        while(i > 0)
        {
            for(int k = 1; k < i; k++)
            j *=10;
            ans = ans + (x%t) * j;
            x -= x%t;
            x /= 10;
            j = 1;
            i--;
        }
        return ans;
}