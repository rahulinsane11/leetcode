class Solution {
public:
    int climbStairs(int n) {
        int dp[46]; // since 1<=n<=45 given in question (we are not using index 0 so n=46)
        dp[1]=1;
        dp[2]=2;
        for(int i=3; i<=n; i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};