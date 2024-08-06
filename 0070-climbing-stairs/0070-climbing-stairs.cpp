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
        dp[0]=1;
        dp[1]=1;
        for(int i=1;i<=n;i++){
            int one=dp[i-1];
            int two=0;
            if(i-2>=0)
                two=dp[i-2];
            dp[i]=one+two;
        }
        return dp[n];

        }
};