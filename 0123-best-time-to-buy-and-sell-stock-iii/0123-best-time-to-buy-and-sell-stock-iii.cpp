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
        vector<vector<int>>prev(2,vector<int>(3,0));
        vector<vector<int>>cur(2,vector<int>(3,0));
        int profit=0;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                for(int cap=1;cap<3;cap++){
        if(j)
        prev[j][cap]=max(cur[0][cap]-prices[i],cur[1][cap]);
        else
        prev[j][cap]=max(cur[1][cap-1]+prices[i],cur[0][cap]);
                }
                cur=prev;
            }
        }
        return cur[1][2];
    }
};