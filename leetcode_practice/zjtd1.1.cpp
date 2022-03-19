#include <iostream>
using namespace std;
const int N = 300000;
int arr[N]; 
int main()
{	
    int n, k, left, right, num;	
    scanf("%d", &n);	
    for (int i = 0; i < n; i++)		
    scanf("%d", &arr[i]);	
    scanf("%d", &k);	
    int res = 0;	
    for (int i = 0; i < k; i++) 
    {		
        res = 0;		
        scanf("%d %d %d", &left, &right, &num);		
        for (int i = left - 1; i <= right - 1; i++) 
        {			
            if (arr[i] == num)				
            res++;		
        }		
        printf("%d\n", res);	
    } 
    
}
