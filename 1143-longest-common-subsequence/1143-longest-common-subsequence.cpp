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
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); // Create a DP table

    // Fill in the DP table to calculate the length of LCS
    for (int ind1 = 1; ind1 <= n; ind1++) {
        for (int ind2 = 1; ind2 <= m; ind2++) {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1]; // Characters match, increment LCS length
            else
                dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]); // Characters don't match, consider the maximum from left or above
        }
    }

    return dp[n][m];
    }
};