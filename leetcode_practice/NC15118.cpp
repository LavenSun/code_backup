#include<bits/stdc++.h>
using namespace std;
set<int> s1;
set<int> s2;
int main(void)
{
    int n, m;
    cin >> n >> m;
    int x, y;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        s1.insert(x);
    }
    for(int i = 0; i < m; i++)
    {
        cin >> x;
        s2.insert(x);
    }
    vector<int> ANS;
    set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(),inserter(ANS,ANS.begin()));
    for(auto it:ANS)
        cout<<it<<" ";
    return 0;
}
//for(set<int>::iterator it=s.begin();it!=s.end();it++)
//printf("%d\n", *it);