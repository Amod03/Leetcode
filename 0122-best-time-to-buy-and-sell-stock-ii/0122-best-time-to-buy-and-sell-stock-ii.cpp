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
        vector<int>next(2,0),cur(2,0);
        int profit=0;
        for(int i=prices.size()-1;i>=0;i--){
            for(int j=0;j<2;j++){
                if(j)
                 profit=max(next[0]-prices[i],next[1]);
                 else
                 profit=max(next[1]+prices[i],next[0]);
                 cur[j]=profit;
            }
            next=cur;
        }
        return next[1];
    }
};