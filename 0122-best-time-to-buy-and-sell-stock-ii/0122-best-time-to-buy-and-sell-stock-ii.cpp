class Solution {
public:
    int solve(int buy,int n,vector<int>& prices,vector<vector<int>>&dp){
        if(n==prices.size()){
            return 0;
        }
        int profit=0;
        if(dp[n][buy]!=-1)return dp[n][buy];
        if(buy)
        profit=max(solve(0,n+1,prices,dp)-prices[n],solve(1,n+1,prices,dp));
        else
        profit=max(solve(1,n+1,prices,dp)+prices[n],solve(0,n+1,prices,dp));
        return dp[n][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int curbuy,curnotbuy,prevbuy,prevnotbuy;
        curbuy=curnotbuy=0;
        int profit=0;
        for(int i=prices.size()-1;i>=0;i--){
                 prevnotbuy=max(curbuy-prices[i],curnotbuy);
                 prevbuy=max(curnotbuy+prices[i],curbuy);
            curnotbuy=prevnotbuy;
            curbuy=prevbuy;
        }
        return curnotbuy;
    }
};