class Solution {
public:
    int trailingZeroes(int n) {
        int x=5,z=0,i=1;
        if(n<5) // no zeros for n! less than 5
            return 0;
        else
        {
            while(i<=5) // Given max value of n=10^4 so max value of i is 5
            {           // since 5^5 < 10^4 < 5^6
                z=z+(n/x); // formula to calculate trailing zeros in n!
                x=x*5;
                i++;
            }
        }
        return z;
    }
};