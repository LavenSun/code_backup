#include <stdio.h>
#include <math.h>

void dfs(int x, int y, int *odd, int *even, char sea[1005][1005], int n)
{
    if (x <= 0 || x > n || y <= 0 || y > n || sea[x][y] == '.')
        return;
    if ((x + y) % 2 == 1)
        (*odd)++;
    else
        (*even)++;
    sea[x][y] = '.';
    dfs(x - 1, y, odd, even, sea, n);
    dfs(x + 1, y, odd, even, sea, n);
    dfs(x, y - 1, odd, even, sea, n);
    dfs(x, y + 1, odd, even, sea, n);
}

int main()
{
    int t, n;
    scanf("%d", &t);
    int x = 1;
    for (int p = 0; p < t; p++)
    {
        scanf("%d", &n);
        int ans = 0;
        char sea[1005][1005] = {0};
        char c;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                scanf("%c", &sea[i][j]);
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (sea[i][j] == '#')
                {
                    int odd = 0, even = 0;
                    dfs(i, j, &odd, &even, sea, n);
                    ans += fmin(odd, even);
                }
            }
        }
        printf("Case %d: %d\n", x++, ans);
    }
    return 0;
}