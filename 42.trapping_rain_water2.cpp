class Solution {
public:
    int trap(vector<int>& height) { // T.C.=O(n) , S.C.=O(1)
        int n=height.size();
        if(n<3) // atleast 3 bars are required to trap water
            return 0;
        int max_left=height[0]; // initially first element is max left
        int max_right=height[n-1]; // initially last element is max right
        int left=1, right=n-2; // left and right pointers
        int water_sum=0;
        while(left<=right)
        {
            if(max_left < max_right)
            {
                if(height[left] < max_left) // current left < max left
                    water_sum = water_sum + (max_left-height[left]); // update total sum
                else
                    max_left=height[left]; // update max left with current left
                left++;
            }
            else
            {
                if(height[right] < max_right) // current right < max right
                    water_sum = water_sum + (max_right-height[right]); // update total sum
                else
                    max_right=height[right]; // update max right with current right
                right--;
            }
        }
        return water_sum;
    }
};