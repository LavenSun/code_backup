class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int n = array.size();
        vector<int> result;
        int x = 0, y = n-1; 
        int times = array[x]*array[y];
        while(x < y)
        {
            if(array[x]+array[y] < sum)
            {
                x++;
            }
            else if(array[x]+array[y] > sum)
            {
                y--;
            }
            else 
            {
                result.push_back(array[x]);
                result.push_back(array[y]);
                break;
            }
        }
        return result;
    }
};
//输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S
//如果有多对数字的和等于S，输出两个数的乘积最小的。