class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>prev(m,0),cur(m,0);
        
        for(int j=0;j<m;j++)
            prev[j]=matrix[0][j];
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int u=matrix[i][j]+prev[j];
                int l=matrix[i][j];
                if(j-1>=0)
                    l=l+prev[j-1];
                else
                    l+=1e8;
                int r=matrix[i][j];
                    if(j+1<m)
                      r=r+prev[j+1];
                else
                    r+=1e8;
              cur[j]=min(u,min(l,r));          

            }
            prev=cur;
        }
        int mini=1e8;
        for(int j=0;j<m;j++)
        {
            mini=min(mini,prev[j]);
        }
        return mini;
    }
};