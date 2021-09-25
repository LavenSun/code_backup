#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    cin >> a[i];
    int maxVal = 0, c = 0;
        for(int i = 0; i <= n-k; i++)
        {
            int x = k;
            while(i+x < n)
            {
                for(int j = i; j< i+x; j++)
                {
                    for(int p = i; p < i+x; p++)
                    {
                        if(a[j] <= a[p])
                            c++;
                    }
                    if(c >= x/2)
                        {
                            if(maxVal < a[j])
                            maxVal = a[j];
                        }
                    c = 0;
                }
                x++;
            }
        }
        cout << maxVal << endl;
        return 0;
}