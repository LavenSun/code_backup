#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
long long cal(int n)
{
    long long sum = 1;
    for(int i = 0; i < n; i++)
        sum *= 10;
    return sum;
}
int main()
{
    int n, m;
    cin >> n >> m;
    string s;
    vector<string> num;
    for(int i = 0; i < m; i++)
    {
        cin >> s;
        num.push_back(s);
    }
    long long sum = 0, sum1 = 0, ans;
    int dif;
    //for(int i = 0; i < m; i++)
    //{
    //    for(int j = 0; j < m; j++)
    //    {
    //        if(num[i].find(num[j]) == 0 && i != j)
    //            num[i] = "no";
    //    }
    //}
    //for(int i = 0; i < m; i++)
    //{
    //   if(num[i] != "no")
    //    {
    //        //dif = n-num[i].size();
    //        sum += cal(n-num[i].size());
    //    }
    //}
    
    
    
    for(int i = 0;i < m ;i ++){
            for(int j = 0 ;j < m;j ++){
                if(num[i].find(num[j]) == 0 && i != j){
                    num[i] = "n";
                }
            }
        }
        for(int i = 0;i < m;i ++){
            if(num[i] != "n"){
                sum1 += cal(n - num[i].size());   
            }
        }
        ans = cal(n)-sum1;
    cout << cal(n)-sum1 << endl;
    return 0;
}