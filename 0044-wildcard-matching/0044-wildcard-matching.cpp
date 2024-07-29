class Solution {
public:
//     bool isAllStars(string &S1, int i) {
//     for (int j = 1; j <= i; j++) {
//         if (S1[j-1] != '*')
//             return false;
//     }
//     return true;
// }

// bool wildcardMatchingUtil(string &S1, string &S2, int i, int j, vector<vector<bool>> &dp) {
//     cout<<i<<j<<endl;
//     if (i== 0 && j == 0)
//         return true;
//     if (i == 0 && j >= 1)
//         return false;
//     if (j == 0 && i >= 1)
//         return isAllStars(S1, i);
//     if (dp[i][j] != false)
//         return dp[i][j];
//     if (S1[i-1] == S2[j-1] || S1[i-1] == '?')
//         return dp[i][j] = wildcardMatchingUtil(S1, S2, i - 1, j - 1, dp);
//     else {
//         if (S1[i-1] == '*')
//             return dp[i][j] = wildcardMatchingUtil(S1, S2, i - 1, j, dp) || wildcardMatchingUtil(S1, S2, i, j - 1, dp);
//         else
//             return false;
//     }
// }
    
    bool isAllStars(string &S1, int i) {
    // S1 is taken in 1-based indexing
    for (int j = 1; j <= i; j++) {
        if (S1[j - 1] != '*')
            return false;
    }
    return true;
}
    
    bool isMatch(string S2, string S1) {
    int n = S1.size();
    int m = S2.size();

    vector<bool>prev(m+1,false),cur(m+1,false);
        prev[0]=true;

        for(int i=1;i<=n;i++){
                    cur[0] = isAllStars(S1, i);
            for(int j=1;j<=m;j++){
        if (S1[i-1] == S2[j-1] || S1[i-1] == '?')
        cur[j] = prev[j - 1];
        else if (S1[i-1] == '*')
        cur[j] = prev[j] || cur[j - 1];
        else
        cur[j]=false;
            
        }
        prev=cur;
        }
            return prev[m];
        
    }
};