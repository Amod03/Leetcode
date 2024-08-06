class Solution {
public:
    int f(int n,vector<int>&dp){
        if(n==0 || n==1)
            return 1;
        if(dp[n] != -1)
            return dp[n];
        int one=f(n-1,dp);
        int two=0;
        if(n-2 >= 0)
         two=f(n-2,dp);
        dp[n]=one+two;
        return dp[n];
    }
    
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return f(n,dp);
    }
};