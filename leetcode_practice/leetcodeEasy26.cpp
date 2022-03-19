#include<iostream>
#include<string>
using namespace std;

int main()
{
    int nums[10] = {0,0,1,1,1,2,2,3,3,4};
     int n = 10;
        int x = n;
        int* array=new int[n];
        // int[] temp=new int[nums.length+1];
        //ListNode* prehead = new ListNode(-1);
        for(int t = 0; t < n; t++)
        array[t] = 0;
        for(int t = 0; t < n; t++)
        array[t] = 0;
        int a[100] = {0};
        int i = 0;
        while(i < n-1)
        {
            if(nums[i] != nums[i+1])
            {
                i++;
            }
            else
            {
                x--;
                array[i+1] = 1;
                i++;
            }
        }
        for(int j = 0; j < n-1; j++)
        {
            if(array[j] == 1)
            {
                for(int k = j+1; k < n; k++)
                {
                    if(array[k] == 0)
                    {
                        int mid1 = nums[j];
                        nums[j] = nums[k];
                        nums[k] = mid1;
                        int mid2 = array[j];
                        array[j] = array[k];
                        array[k] = mid2;
                    }
                }
            }
        }
        for(int y = 0; y < x; y++)
        {
            for(int q = y+1; q < x; q++)
            {
                if(nums[y] > nums[q])
                {
                int mid3;
                mid3 = nums[q];
                nums[q] = nums[y];
                nums[y] = mid3;
                }
            }
        }
        for(int p = 0; p < x; p++)
        cout << nums[p] << " ";
    return 0;
}