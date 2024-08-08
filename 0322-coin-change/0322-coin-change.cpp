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
        vector<int>prev(target+1,0);
        for(int i=0;i<=target;i++){
            if(i%coins[0]==0)
                prev[i]=i/coins[0];
            else
                prev[i]=1e9;
        }
        
        for(int i=1;i<coins.size();i++){
            for(int j=0;j<=target;j++){
                int take=1e9;
                int notTake=prev[j];
            
                if(coins[i]<=j)
              take=1+prev[j-coins[i]];
              
                prev[j]=min(take,notTake);
            }
        }
        int ans=prev[target];
         if(ans >= 1e9)
         return -1;
         return ans;
    }
};