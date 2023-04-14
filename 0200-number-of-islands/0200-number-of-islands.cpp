class Solution {
    private:
     vector<int> x = {+1, -1, 0, 0};
    vector<int> y = {0, 0, +1, -1};        
    void bfs(int row,int col,vector<vector<int>>& vis,vector<vector<char>> grid)
    {
        vis[row][col]=1;
        queue<pair<int,int>>q;
        q.push({row,col});
        int n=grid.size();
        int m=grid[0].size();
        
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            
            //traverse all the 4 neighbours easily
            for(int k=0; k<4; k++){
                int nrow = row+x[k];
                int ncol = col+y[k];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && !vis[nrow][ncol])
                    {
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol}); 
                    }
                    }
                }
            
        }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt=0;
        for(int row=0;row<n;row++)
        {
            for(int col=0;col<m;col++)
            {
                if(!vis[row][col] && grid[row][col]=='1')
                {
                    cnt++;
                    bfs(row,col,vis,grid);
                }
            }
        }
        return cnt;
    }
};