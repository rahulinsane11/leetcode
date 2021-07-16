class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n; // to reduce k in the range(0,n-1)
        reverse_array(nums,0,n-1); // reverse all the elements
        reverse_array(nums,0,k-1); // reverse the first k elements
        reverse_array(nums,k,n-1); // reverse the remaining (n-k) elements
    }
    
    void reverse_array(vector<int>& nums, int start, int end)
    {
        int temp;
        while(start<end)
        {
            temp=nums[start];
            nums[start]=nums[end];
            nums[end]=temp;
            start++;
            end--;
        }
    }
};