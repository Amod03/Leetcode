class Solution {
public:
    int solve(int n,int m,int l,vector<vector<int>>& triangle,vector<vector<int>>& dp){
      if(n == l-1) return triangle[n][m];
        if(dp[n][m]!=-1)
            return dp[n][m];
        int left=triangle[n][m]+solve(n+1,m+1,l,triangle,dp);
            int right=triangle[n][m]+solve(n+1,m,l,triangle,dp);
        return dp[n][m]=min(left,right);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(0,0,n,triangle,dp);
    }
};