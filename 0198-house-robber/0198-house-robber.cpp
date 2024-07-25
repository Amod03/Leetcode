class Solution {
public:
    int solve(vector<int>&arr,int sum,int n,vector<int>&dp){
        if(n==0)
            return arr[0];
        if(n<0)
            return 0;
        if(dp[n]!=-1)return dp[n];
        int pick=INT_MIN;
            pick=sum+arr[n]+solve(arr,sum,n-2,dp);
        int nonpick=sum+solve(arr,sum,n-1,dp);
        return dp[n]=max(pick,nonpick);
    }
    int rob(vector<int>& arr) {
       int sum=0;
        int n=arr.size();
        vector<int>dp(n,-1);
        return solve(arr,sum,n-1,dp);
    }
};