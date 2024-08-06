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
        for(int i=0;i<n;i++){
            dp[i][0]=1;
        }
            for(int j=0;j<m;j++){
                dp[0][j] = 1;
            }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
            int top=dp[i-1][j];
            int left=dp[i][j-1];
            dp[i][j]=top+left;
            }
        }
     return dp[n-1][m-1];
    }
};