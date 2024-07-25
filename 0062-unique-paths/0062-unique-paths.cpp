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
        vector<int>prev(m,-1);
        for(int i=0;i<n;i++){
            vector<int>cur(m,-1);
            for(int j=0;j<m;j++){
             if (i == 0 && j == 0) {
                cur[j] = 1;
                continue; 
            }
            int top=0;
            if(i>0)
            top=prev[j];
            int left=0;
            if(j>0)
            left=cur[j-1];
            cur[j]=top+left;
            }
            prev=cur;
        }
     return prev[m-1];
    }
};