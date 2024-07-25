class Solution {
public:
    int solve(int n,int m,vector<vector<int>>&dp){
        if(n==0 && m==0) return 1;
        if(n<0 || m<0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        int top=solve(n-1,m,dp);
        int left=solve(n,m-1,dp);
        return dp[n][m]=top+left;
    }
    int uniquePaths(int n, int m) {
        vector<vector<int>>dp(n,vector<int>(m,-1));
     return solve(n-1,m-1,dp);
    }
};