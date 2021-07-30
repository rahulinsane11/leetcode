class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int c=0,max=0;
        for(int i=0; i<n; i++)
        {
            if(nums[i]==1)
            {
                c++;
                if(c > max)
                    max=c;
            }
            else
                c=0;
        }
        return max;
    }
};