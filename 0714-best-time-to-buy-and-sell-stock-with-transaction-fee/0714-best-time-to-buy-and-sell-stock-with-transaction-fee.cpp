class Solution {
public:
    int solve(int buy,int n,vector<int>& prices,vector<vector<int>>&dp,int fee){
        if(n>=prices.size()){
            return 0;
        }
        int profit=0;
        if(dp[n][buy]!=-1)return dp[n][buy];
        if(buy)
        profit=max(solve(0,n+1,prices,dp,fee)-prices[n],solve(1,n+1,prices,dp,fee));
        else
        profit=max(solve(1,n+1,prices,dp,fee)+prices[n]-fee,solve(0,n+1,prices,dp,fee));
        return dp[n][buy]=profit;
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(1,0,prices,dp,fee);
    }
};