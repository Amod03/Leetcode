class Solution {
public:
    int solve(int buy,int n,vector<int>& prices,vector<vector<int>>&dp){
        if(n>=prices.size()){
            return 0;
        }
        int profit=0;
        if(dp[n][buy]!=-1)return dp[n][buy];
        if(buy)
        profit=max(solve(0,n+1,prices,dp)-prices[n],solve(1,n+1,prices,dp));
        else
        profit=max(solve(1,n+2,prices,dp)+prices[n],solve(0,n+1,prices,dp));
        return dp[n][buy]=profit;
    }
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(1,0,prices,dp);
    }
};