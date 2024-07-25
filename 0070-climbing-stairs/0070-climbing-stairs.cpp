class Solution {
public:
    int solve(int n,vector<int>&dp){
        if(n==0)
            return 1;
        if(dp[n]!=-1)
            return dp[n];
        int left=solve(n-1,dp);
        int right=0;
        if(n-2>=0)
        right=solve(n-2,dp);
        return dp[n]=left+right;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        int prev=1;
        int curr=1;
        for(int i=2;i<=n;i++){
            int newcur=prev+curr;
            prev=curr;
            curr=newcur;
        }
        return curr;
    }
};