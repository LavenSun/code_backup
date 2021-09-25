#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int step[2000000 + 5];
    memset(step, 0x3f, sizeof(step));
    if (n == m) return 0;
    step[n] = 1;
    queue<int> q;
    q.push(n);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        int tmp = x - 1;
        if (tmp == m)
            return step[x];
        if (tmp >= 0 && tmp <= 2000 && step[tmp] > step[x] + 1)
        {
            step[tmp] = step[x] + 1;
            q.push(tmp);
        }
        tmp = x + 1;
        if (tmp == m)
            return step[x];
        if (tmp >= 0 && tmp <= 2000 && step[tmp] > step[x] + 1)
        {
            step[tmp] = step[x] + 1;
            q.push(tmp);
        }
        tmp = x * x;
        if (tmp == m)
            return step[x];
        if (tmp >= 0 && tmp <= 2000 && step[tmp] > step[x] + 1)
        {
            step[tmp] = step[x] + 1;
            q.push(tmp);
        }
    }
    return 0;
}
