class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
    
        int Count=0;
        if(n<1) return 0;
        for(int i=1;i<=n;++i)
            {
            int temp=i;
            while(temp)
                {
                if(temp%10==1)
                    ++Count;
                temp/=10;
            }
        }
        return Count;
    }
};
