class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i,j,n=nums.size(),sum,max=nums[0];
        for(i=0; i<n; i++)
        {
            sum=0;
            for(j=i; j<n; j++)
            {
                sum=sum+nums[j];
                if(sum>max)
                    max=sum;
            }
        }
        return max;
    }
};