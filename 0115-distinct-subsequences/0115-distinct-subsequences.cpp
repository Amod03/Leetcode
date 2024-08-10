class Solution {
public:
    
    int countUtil(string s1, string s2, int ind1, int ind2, vector<vector<int>>& dp) {
    if (ind2 < 0)
        return 1;
    if (ind1 < 0)
        return 0;
    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];

    int result = 0;
    if (s1[ind1] == s2[ind2]) {
        int leaveOne = countUtil(s1, s2, ind1 - 1, ind2 - 1, dp);
        int stay = countUtil(s1, s2, ind1 - 1, ind2, dp);

        result = (leaveOne + stay) ;
    } else {
        result = countUtil(s1, s2, ind1 - 1, ind2, dp);
    }
    dp[ind1][ind2] = result;
    return result;
}
    
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
    vector<double>prev(m + 1, 0);

    for (int i = 1; i <= n; i++) {
        prev[0]=1;
        for (int j = m; j >=1; j--) {
            if (s[i - 1] == t[j - 1]) {
                prev[j] = (prev[j - 1] + prev[j]) ;
            } else {
                prev[j] = prev[j];
            }
        }
    }
    return (int)prev[m];
    }
};