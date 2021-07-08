class Solution {
public:
    bool isPalindrome(string s) {
        char arr[200000];
        int n=s.length(),k=0;
        for(int i=0; i<n; i++)
        {
            if((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9'))
            {
                arr[k]=s[i];
                k++;
            }
            else if(s[i]>='A' && s[i]<='Z') 
            {
                arr[k]=s[i]+32; // convert uppercase to lowercase
                k++;
            }
        }
        for(int i=0,j=k-1; i<=j; i++,j--)
        {
            if(arr[i]!=arr[j])
                return false;
        }
        return true;
    }
};