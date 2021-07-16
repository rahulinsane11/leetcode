class Solution {
public:
    string reverseVowels(string s) {
        int n=s.length();
        int left=0,right=n-1;
        char temp;
        while(left<right)
        {
            if(isVowel(s[left]) == 0) // increment left if s[left] is not a vowel
               left++;
            if(isVowel(s[right]) == 0) // decrement right if s[right] is not a vowel
               right--;
            if(isVowel(s[left])==1 && isVowel(s[right])==1) // swap s[left] and s[right] if both are vowel
            {
                temp=s[left];
                s[left]=s[right];
                s[right]=temp;
                left++;
                right--;
            }
        }
        return s;
    }

    int isVowel(char ch) // return 1 if input character is a vowel and 0 otherwise
    {
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
            return 1;
        else if(ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U')
            return 1;
        return 0;
    }
};