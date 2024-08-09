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
        int n = text1.size();
    int m = text2.size();
    vector<int> prev(m + 1, 0);
    
    for (int i = 1; i <= n; i++) {
        int prevDiag = 0;  // This will store dp[i-1][j-1]
        for (int j = 1; j <= m; j++) {
            int temp = prev[j];  // Store the current dp[j] before updating
            if (text1[i - 1] == text2[j - 1]) {
                prev[j] = prevDiag + 1;
            } else {
                prev[j] = max(prev[j], prev[j - 1]);
            }
            prevDiag = temp;  // Update prevDiag to the previous dp[j]
        }
    }
    
    return prev[m];
    }
};