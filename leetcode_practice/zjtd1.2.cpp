#include <iostream>
#include <unordered_map>
using namespace std;
const int N = 300000;
int arr[N]; 
int main()
{	
    int n, k, left, right, num;	
    unordered_multimap<int, int> mp;	
    scanf("%d", &n);	
    for (int i = 0; i < n; i++) 
    {		
        scanf("%d", &arr[i]);		
        mp.insert(make_pair(arr[i], i));	
    }			
    scanf("%d", &k);	
    int res = 0;	
    for (int i = 0; i < k; i++) 
    {		
        res = 0;		
        scanf("%d %d %d", &left, &right, &num);		
        auto iter = mp.find(num);		
        int size = mp.count(num);		
        for (int j = 0; j != size; j++, ++iter) 
        {			
            if (iter->second >= left - 1 && iter->second <= right - 1)				
            res++;		
        }		
        printf("%d\n", res);	
    }
}
