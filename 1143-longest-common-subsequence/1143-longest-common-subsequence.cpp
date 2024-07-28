class Solution {
public:
    int solve(int n,int m,string text1, string text2,vector<vector<int>>&dp)
    {
        if(n<0 || m<0)
            return 0;
        
        if(dp[n][m]!=-1)
            return dp[n][m];
        if(text1[n]==text2[m])
            return 1+solve(n-1,m-1,text1,text2,dp);
        
        return dp[n][m]=max(solve(n-1,m,text1,text2,dp),solve(n,m-1,text1,text2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
            if(text1[i]==text2[j]){
              dp[i][j]= 1;
                  if(i>0 && j>0)
                  dp[i][j]=dp[i][j]+dp[i-1][j-1];
            }else{
                int first=0;
                if(i>0)
                    first=dp[i-1][j];
                int second=0;
                if(j>0)
                    second=dp[i][j-1];

            dp[i][j]=max(first,second);
            }
            }
        }
        return dp[n-1][m-1];
    }
};