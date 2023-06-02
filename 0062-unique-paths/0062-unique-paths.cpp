class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int>prev(n,0);
        
        for(int i=0;i<m;i++)
        {
            vector<int>cur(n,0);
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                    cur[i]=1;
                else
                {
                    int left=0;
                    if(j>0)
                        left=cur[j-1];
                cur[j]=left+prev[j];
                }
            }
            prev=cur;
         }
        return prev[n-1];
    }
};