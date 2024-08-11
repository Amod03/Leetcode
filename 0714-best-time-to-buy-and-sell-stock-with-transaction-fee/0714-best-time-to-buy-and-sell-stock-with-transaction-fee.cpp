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
        vector<int>prev(2,0);
        int profit=0;
        for(int i=prices.size()-1;i>=0;i--){
            for(int j=0;j<2;j++){
                if(j)
                 profit=max(prev[0]-prices[i],prev[1]);
                 else
                 profit=max(prev[1]+prices[i]-fee,prev[0]);
                 prev[j]=profit;
            }
        }
        return prev[1];
    }
};