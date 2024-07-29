class Solution {
public:
    
    int editDistanceUtil(string& S1, string& S2, int i, int j, vector<vector<int>>& dp) {
    if (i == 0)
        return j ;
    if (j == 0)
        return i ;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (S1[i-1] == S2[j-1])
        return dp[i][j] = 0 + editDistanceUtil(S1, S2, i - 1, j - 1, dp);
    else
        return dp[i][j] = 1 + min(editDistanceUtil(S1, S2, i - 1, j - 1, dp),
                                  min(editDistanceUtil(S1, S2, i - 1, j, dp),
                                      editDistanceUtil(S1, S2, i, j - 1, dp)));
}

    
    int minDistance(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    return editDistanceUtil(text1, text2, n, m , dp);
    }
};