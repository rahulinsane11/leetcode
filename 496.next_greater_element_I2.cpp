class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(), n2=nums2.size();
        vector<int> ans(n1);
        stack<int> st;
        unordered_map<int,int> mp; // stores NGE of all elements in nums2
        for(int j=0; j<n2; j++)
        {
            int curr=nums2[j];
            while(!st.empty() && curr > st.top())
            {
                mp[st.top()]=curr;
                st.pop();
            }
            st.push(curr);
        }
        while(!st.empty()) // elements remaining in stack do not have any NGE 
        {
            mp[st.top()]=-1;
            st.pop();
        }
        for(int i=0; i<n1; i++)
        {
            int curr=nums1[i];
            auto it = mp.find(curr); // iterator
            if(it!=mp.end()) // value is found in map
                ans[i]=mp[curr];
        }
        return ans;
    }
};