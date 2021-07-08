class Solution {
public:
    int climbStairs(int n) {
        if(n<=2)
            return n;
        int x=1,y=2,temp;
        for(int i=3; i<=n; i++)
        {
            temp=x+y;
            x=y;
            y=temp;
        }
        return y;
    }
};