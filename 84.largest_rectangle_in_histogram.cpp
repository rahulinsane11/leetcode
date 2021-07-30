class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> left(n), right(n); // contains index (not elements)
        stack<int> st; // stack contains index (not elements)

        st.push(0); // push the first index into stack
        left[0]=0; // for the 0th index- the leftmost index is itself
        for(int i=1; i<n; i++) // left index limit of each element 
        {
            while(!st.empty() && heights[st.top()] >= heights[i]) // from the left side - remove the bars with height >= current bar
                st.pop();
            if(st.empty())
                left[i]=0; // leftmost index
            else
                left[i]=st.top()+1;
            st.push(i);
        }
        
        while(!st.empty()) // clear the stack
            st.pop();
        
        st.push(n-1); // push the last index into stack
        right[n-1]=n-1; // for the last index- the rightmost index is itself
        for(int i=n-2; i>=0; i--) // right index limit of each element 
        {
            while(!st.empty() && heights[st.top()] >= heights[i]) // from the right side - remove the bars with height >= current bar
                st.pop();
            if(st.empty())
                right[i]=n-1; // rightmost index
            else
                right[i]=st.top()-1;
            st.push(i);
        }
        
        while(!st.empty()) // clear the stack
            st.pop();
        
        int max_area=0;
        for(int i=0; i<n; i++)
        {
            int curr_area=heights[i]*(right[i]-left[i]+1);
            if(curr_area > max_area)
                max_area=curr_area;
        }
        return max_area;
    }
};