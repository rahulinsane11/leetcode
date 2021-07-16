class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> vec(n);
        int c=k, i=0;
        while(i<n)
        {
            c=c%n; // make the counter return to 0th index after reaching (n-1)th index
            vec[c]=nums[i];
            c++;
            i++;
        }
        for(i=0; i<n; i++)
            nums[i]=vec[i];
    }
};