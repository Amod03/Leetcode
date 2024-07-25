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
        int prev=arr[0];
        int prev1=0;
        for(int i=1;i<n;i++){
            int pick=arr[i];
            if(i>1)
            pick=pick+prev1;
         int nonpick=prev;  
         int cur=max(pick,nonpick);
            prev1=prev;
            prev=cur;
        }
        return prev;
    }
};