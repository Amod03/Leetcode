class Solution {
public:
    int solve(int n,int transaction,vector<int>& prices, vector<vector<int>>&dp){
        if(n==prices.size() || transaction==4){
            return 0;
        }
        int profit=0;
        if(dp[n][transaction]!=-1) return dp[n][transaction];
        if(transaction%2==0)
        profit=max(solve(n+1,transaction+1,prices,dp)-prices[n],solve(n+1,transaction,prices,dp));
        else
        profit=max(solve(n+1,transaction+1,prices,dp)+prices[n],solve(n+1,transaction,prices,dp));
        return dp[n][transaction]=profit;
    }
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(4,-1));
        return solve(0,0,prices,dp);
    }
};