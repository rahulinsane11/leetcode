class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=s.size();
        int start=0, end=n-1, temp;
        while(start<end)
        {
            temp=s[start];
            s[start]=s[end];
            s[end]=temp;
            start++;
            end--;
        }
    }
};