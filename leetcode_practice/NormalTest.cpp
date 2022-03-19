#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string str = "nowcoder";
    int n = str.size(), i = 0;
    string ans = "";
    while (str[i] != ' ')
    {
        ans += str[i];
        i++;
    }
    i++;
    string tmp = "";
    while (i < n)
    {
        if (str[i] != ' ')
            tmp += str[i];
        else
        {
            ans = tmp + ' ' + ans;
            tmp = "";
        }
        i++;
    }
    ans = tmp + ' ' + ans;
    cout << ans << endl;
    return 0;
}
