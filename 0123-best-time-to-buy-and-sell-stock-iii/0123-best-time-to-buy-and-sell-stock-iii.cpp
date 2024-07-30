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
        vector<int>prev(5,0),cur(5,0);
        for(int i=n-1;i>=0;i--){
            for(int transaction=0;transaction<4;transaction++){
            if(transaction%2==0)
        prev[transaction]=max(cur[transaction+1]-prices[i],cur[transaction]);
        else
        prev[transaction]=max(cur[transaction+1]+prices[i],cur[transaction]);
            }
            cur=prev;
        }
        return cur[0];
    }
};