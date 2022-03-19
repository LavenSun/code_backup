#include<iostream>
#include<string>
using namespace std;
int main()
    {
        string senate;
        cin >> senate;
        int n = senate.size();
        int R_Number = 0, D_Number = 0;
        int Against_R = 0, Against_D = 0;
        for(int i = 0; i < n; i++)
        {
            if(senate[i] == 'R')
            R_Number++;
            if(senate[i] == 'D')
            D_Number++;
        }
        for(int i = 0; i < n; i++)
        {
            if(senate[i] == 'R' && !Against_R)
            {
                if(!D_Number)
                cout << "Radiant";
                else
                {
                    Against_D++;
                }
            }
            else if(senate[i] == 'R' && Against_R)
            {
                Against_R--;
                R_Number--;
            }
            if(senate[i] == 'D' && !Against_D)
            {
                if(!R_Number)
                cout << "Dire";
                else
                {
                    Against_R++;
                }
            }
            else if(senate[i] == 'D' && Against_D)
            {
                Against_D--;
                D_Number--;
            }
        }
        if(R_Number > D_Number)
        cout << "Radiant";
        else if(R_Number < D_Number)
        cout << "Dire";
        else 
        {
            if(senate[n-1] == 'R')
            cout << "Radiant";
            else cout << "Dire";
        }
        return 0;
    }