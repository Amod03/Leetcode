class Solution {
public:
    
    int solve(int n,int target,vector<int>&coins,vector<vector<int>>&dp){
        if(n==0){
            if(target % coins[0] == 0)
            return 1; 
        else
            return 0; 
        }
        if(dp[n][target]!=-1)return dp[n][target];
        int take=0;
        if(coins[n]<=target)
        take=solve(n,target-coins[n],coins,dp);
        int notTake=solve(n-1,target,coins,dp);
        return dp[n][target]=take+notTake;
    }
    
    int change(int target, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(coins.size(),vector<int>(target+1,-1));
        return solve(n-1,target,coins,dp);
        }
};