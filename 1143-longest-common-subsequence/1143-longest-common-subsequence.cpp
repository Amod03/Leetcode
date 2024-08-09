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
    
    // Create a 1D array to store the results of the previous row
    vector<int> dp(m + 1, 0);
    
    for (int i = 1; i <= n; i++) {
        int prev = 0; // This will store the dp[i-1][j-1] value
        
        for (int j = 1; j <= m; j++) {
            int temp = dp[j]; // Store the current dp[j] before updating
            
            if (text1[i - 1] == text2[j - 1]) {
                dp[j] = prev + 1;
            } else {
                dp[j] = max(dp[j], dp[j - 1]);
            }
            
            prev = temp; // Update prev to the value of dp[j] before modification
        }
    }
    
    return dp[m];
    }
};