class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0; i<n-2; i++)
        {
            if(i>0 && nums[i]==nums[i-1]) // to handle duplicates
                continue;
            int j=i+1, k=n-1;
            while(j<k)
            {
                if(nums[i]+nums[j]+nums[k] == 0)
                {
                    ans.push_back( vector<int>{nums[i],nums[j],nums[k]} );
                    while(j<k && nums[j]==nums[j+1]) // to handle duplicates
                        j++;
                    while(j<k && nums[k]==nums[k-1]) // to handle duplicates
                        k--;
                    j++;
                    k--;
                }
                else if(nums[i]+nums[j]+nums[k] > 0)
                    k--;
                else
                    j++;
            }
        }
        return ans;
    }
};