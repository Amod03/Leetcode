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
        vector<vector<int>>dp(prices.size()+2,vector<int>(2,0));
        int profit=0;
        for(int i=prices.size()-1;i>=0;i--){
            for(int j=0;j<2;j++){
                if(j)
                 profit=max(dp[i+1][0]-prices[i],dp[i+1][1]);
                 else
                 profit=max(dp[i+1][1]+prices[i]-fee,dp[i+1][0]);
                 dp[i][j]=profit;
            }
        }
        return dp[0][1];
    }
};