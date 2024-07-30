class Solution {
public:
    int solve(int buy,int n,int cap,vector<int>& prices, vector<vector<vector<int>>>&dp){
        if(n==prices.size()){
            return 0;
        }
        if(cap==0)
            return 0;
        int profit=0;
        if(dp[n][buy][cap]!=-1)return dp[n][buy][cap];
        if(buy)
        profit=max(solve(0,n+1,cap,prices,dp)-prices[n],solve(1,n+1,cap,prices,dp));
        else
        profit=max(solve(1,n+1,cap-1,prices,dp)+prices[n],solve(0,n+1,cap,prices,dp));
        return dp[n][buy][cap]=profit;
    }
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(2,vector<int>(3,0)));
        int profit=0;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                for(int cap=1;cap<3;cap++){
        if(j)
        profit=max(dp[i+1][0][cap]-prices[i],dp[i+1][1][cap]);
        else
        profit=max(dp[i+1][1][cap-1]+prices[i],dp[i+1][0][cap]);
        dp[i][j][cap]=profit;
                }
            }
        }
        return dp[0][1][2];
    }
};