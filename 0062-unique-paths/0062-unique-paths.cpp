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
            for(int j=0;j<m;j++){
             if (i == 0 && j == 0) {
                dp[i][j] = 1;
                continue; 
            }
            int top=0;
            if(i>0)
            top=dp[i-1][j];
            int left=0;
            if(j>0)
            left=dp[i][j-1];
            dp[i][j]=top+left;
            }
        }
     return dp[n-1][m-1];
    }
};