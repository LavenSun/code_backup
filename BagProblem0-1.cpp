#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() //0-1背包问题的动态规划求解
{
    int T, M;
    cin >> T >> M;
    vector<int> t(M+1);
    vector<int> v(M+1);
    //int t[M+1], v[M+1];
    t[0] = v[0] = 0;
    for(int i = 1; i <= M; i++)
        cin >> t[i] >> v[i];
    vector<vector<int>> dp(M+1, vector<int>(T+1));
    //int dp[M+1][T+1];
    for(int i = 0; i <= T; i++)
        dp[0][i] = 0;
    for(int i = 0; i <= M; i++)
        dp[i][0] = 0;
    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= T; j++)
        {
            if (t[i] <= j)
                dp[i][j] = max(dp[i-1][j], v[i]+dp[i-1][j-t[i]]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[M][T] << endl;
    return 0;
}
//https://blog.csdn.net/wmy01234/article/details/105622517?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-6.channel_param&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-6.channel_param