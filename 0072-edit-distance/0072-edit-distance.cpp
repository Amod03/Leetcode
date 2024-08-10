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
        int n = text1.size();
    int m = text2.size();
    vector<int> dp(m + 1, 0);
    
    for (int j = 0; j <= m; j++) {
        dp[j] = j;
    }
    
    for (int i = 1; i <= n; i++) {
        int prev = dp[0];
        dp[0] = i;
        for (int j = 1; j <= m; j++) {
            int temp = dp[j];
            if (text1[i - 1] == text2[j - 1]) {
                dp[j] = prev;
            } else {
                dp[j] = 1 + min({prev, dp[j], dp[j - 1]});
            }
            prev = temp;
        }
    }
    
    return dp[m];
    }
};