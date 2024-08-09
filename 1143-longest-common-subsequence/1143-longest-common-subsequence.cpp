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

    vector<int>prev(m + 1, 0); 

    for (int ind1 = 1; ind1 <= n; ind1++) {
        int dia=0;
        for (int ind2 = 1; ind2 <= m; ind2++) {
            int temp=prev[ind2];
            if (s1[ind1 - 1] == s2[ind2 - 1])
                prev[ind2] = 1 + dia; 
            else
                prev[ind2] = max(prev[ind2], prev[ind2 - 1]); 
            dia=temp;
        }
    }
    return prev[m];
    }
};