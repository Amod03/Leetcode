class Solution {
public:
    int solve(int n,int m,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(n==0 && m==0)return grid[n][m];
        if(n<0 || m<0)return 1e9;
        if(dp[n][m]!=-1)return dp[n][m];
        int left=grid[n][m]+solve(n,m-1,grid,dp);
        int right=grid[n][m]+solve(n-1,m,grid,dp);
        return dp[n][m]=min(left,right);
    }
int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>prev(m,0),cur(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 & j==0){
                    cur[j]=grid[i][j];
                    continue;
                }
                int left=1e9;
                if(j>0)
                left=grid[i][j]+cur[j-1];
                int right=1e9;
                if(i>0)
                right=grid[i][j]+prev[j];
                cur[j]=min(left,right);
         }
            prev=cur;
        }
        return prev[m-1];
    }
};