#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int len = s.size();
    int pos_to_fit = 0;
    for(int i = 0; i < len; i++)
    {
        if(s[i] != 'a')
        {
            if( i > pos_to_fit)
            {
                s[pos_to_fit] = s[i];
            }
                 
            pos_to_fit++;
        }
    }
    for(int i = pos_to_fit ; i < len; i++)
    {
        s[i] = 'a';
    }
    cout << s;
    return 0;
}
