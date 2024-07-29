class Solution {
public:
    int longestPalindromeSubseq(string text1) {
        string text2=text1;
            reverse(text2.begin(),text2.end());
        int n=text1.size();
        int m=text2.size();
        vector<int>prev(m+1,0);
        for(int i=1;i<=n;i++){
            vector<int>cur(m+1,0);
            for(int j=1;j<=m;j++){
            if(text1[i-1]==text2[j-1]){
              cur[j]= 1+prev[j-1];
            }else{
                    int first=prev[j];
                    int second=cur[j-1];

            cur[j]=max(first,second);
            }
            }
            prev=cur;
        }
        return prev[m];
    }
};