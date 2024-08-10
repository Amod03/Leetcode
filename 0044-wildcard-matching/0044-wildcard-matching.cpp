class Solution {
public:
    
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

    vector<bool>prev(m+1, false);
        prev[0]=true;

        for(int i=1;i<=n;i++){
            int diag=prev[0];
            prev[0] = isAllStars(S1, i);

            for(int j=1;j<=m;j++){
                int temp=prev[j];
        if (S1[i-1] == S2[j-1] || S1[i-1] == '?')
        prev[j] = diag;
        else if (S1[i-1] == '*')
        prev[j] = prev[j] | prev[j - 1];
        else
        prev[j]=false;
            diag=temp;
        }}
            return prev[m];
        
    }
};