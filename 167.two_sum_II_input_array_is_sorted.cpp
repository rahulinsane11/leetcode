class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans(2);
        int n=numbers.size();
        int left=0, right=n-1, mid;
        while(left<right)
        {
            if(numbers[left]+numbers[right] == target)
            {
                ans[0]=left+1;
                ans[1]=right+1;
                return ans;
            }
            else if(numbers[left]+numbers[right] > target)
                right--;
            else
                left++;
        }
        return ans;
    }
};