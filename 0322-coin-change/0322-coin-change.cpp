class Solution {
public:
    int solve(int n,int target,vector<int>&coins,int mini,vector<vector<int>>&dp){
        if(n==0){
            if(target % coins[0] == 0)
            return target / coins[0]; 
        else
            return 1e9; 
        }
        if(dp[n][target]!=-1)return dp[n][target];
        int take=1e9;
        if(coins[n]<=target)
        take=1+solve(n,target-coins[n],coins,mini,dp);
        int notTake=solve(n-1,target,coins,mini,dp);
        return dp[n][target]=min(take,notTake);
    }
    int coinChange(vector<int>& coins, int target) {
        int mini=INT_MAX;
        vector<vector<int>>dp(coins.size(),vector<int>(target+1,-1));
        int ans=solve(coins.size()-1,target,coins,mini,dp);
         if(ans >= 1e9)
        return -1;
    return ans;
    }
};