class Solution {
public:
    int solve(vector<int>&arr,int n,vector<int>&dp){
        if(n==0)
            return arr[0];
        if(n<0)
            return 0;
        if(dp[n]!=-1)return dp[n];
        int pick=INT_MIN;
            pick=arr[n]+solve(arr,n-2,dp);
        int nonpick=solve(arr,n-1,dp);
        return dp[n]=max(pick,nonpick);
    }
    int rob(vector<int>& arr) {
        int n=arr.size();
        vector<int>dp(n,-1);
        dp[0]=arr[0];
        for(int i=1;i<n;i++){
            int pick=arr[i];
            if(i>1)
            pick=pick+dp[i-2];
         int nonpick=dp[i-1];  
         dp[i]=max(pick,nonpick);
        }
        return dp[n-1];
    }
};