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
        vector<int>prev(m,1),cur(m,0);
        cur[0]=1;
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
            int top=prev[j];
            int left=cur[j-1];
            cur[j]=top+left;
            }
            prev=cur;
        }
     return prev[m-1];
    }
};