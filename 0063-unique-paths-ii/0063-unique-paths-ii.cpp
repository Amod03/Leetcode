class Solution {
public:
    public:
    int solve(int n,int m,vector<vector<int>>&dp,vector<vector<int>>&obstacleGrid){
        if(n>-1 && m>-1 && obstacleGrid[n][m]==1)return 0;
        if(n==0 && m==0) return 1;
        if(n<0 || m<0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        int top=solve(n-1,m,dp,obstacleGrid);
        int left=solve(n,m-1,dp,obstacleGrid);
        return dp[n][m]=top+left;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
      int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,dp,obstacleGrid);
    }
};