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
        vector<int>prev(m,-1),cur(m,-1); 
        for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i >=0 && j >= 0 && obstacleGrid[i][j] == 1) {
                cur[j] = 0; 
                continue;
            }
            if (i == 0 && j == 0) {
                cur[j] = 1; 
                continue;
            }
            int up = 0;
            int left = 0;
            if (i > 0)
                up = prev[j]; 
            if (j > 0)
                left = cur[j - 1]; 
            cur[j] = up + left;
        }
            prev=cur;
    }
    // The final result is stored in dp[n-1][m-1], which represents the destination
    return prev[m - 1];
    }
};