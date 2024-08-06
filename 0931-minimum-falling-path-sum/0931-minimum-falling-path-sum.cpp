class Solution {
public:
    int solve(int start,int end,int n,vector<vector<int>>& matrix,vector<vector<int>>& dp){
        if (end < 0 || end > n) return 1e9; 
        if(start==n) return matrix[start][end];
        if(dp[start][end]!=-1) return dp[start][end];

        int left=matrix[start][end]+solve(start+1,end-1,n,matrix,dp);                                         int down=matrix[start][end]+solve(start+1,end,n,matrix,dp);
        int right=matrix[start][end]+solve(start+1,end+1,n,matrix,dp);
        return min(left,min(down,right));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int mini=INT_MAX;
        vector<int>prev(n,0),cur(n,0);
        
        for(int i=0;i<n;i++){
            prev[i]=matrix[n-1][i];
        }
        
        for(int i=n-2;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int left=1e9;
                if(j>0)
                left=matrix[i][j]+prev[j-1];
                int down=matrix[i][j]+prev[j];
                int right=1e9;
                if(j<n-1)
                right=matrix[i][j]+prev[j+1];
                cur[j]=min(left,min(down,right));
            }
            prev=cur;
        }
        
        for(int i=0;i<n;i++){
            mini=min(mini,prev[i]);
        }
        return mini;
    }
};