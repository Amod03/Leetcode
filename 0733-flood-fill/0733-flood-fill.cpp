class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>&ans,vector<vector<int>>& image,int newColor,int delRow[],int delCol[],int iniColor)
    {
        ans[row][col]=newColor;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++)
        {
            int nrow=row+delRow[i];
            int ncol=col+delCol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==iniColor && ans[nrow][ncol]!=newColor)
                dfs(nrow,ncol,ans,image,newColor,delRow,delCol,iniColor);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int iniColor=image[sr][sc];
        vector<vector<int>>ans=image;
        // int delRow[]={-1,0,+1,0};
        // int delCol[]={0,+1,0,-1};
        // dfs(sr,sc,ans,image,newColor,delRow,delCol,iniColor);
        // return ans;
        // if(image.empty()) return 0;
        int m = image.size(), n = image[0].size(), days = 0, tot = 0, cnt = 0;
        queue<pair<int, int>> rotten;
        rotten.push({sr,sc});
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        ans[sr][sc] = newColor;
        while(!rotten.empty()){
                int x = rotten.front().first, y = rotten.front().second;
                rotten.pop();
                for(int i = 0; i < 4; ++i){
                    int nx = x + dx[i], ny = y + dy[i];
                    if(nx < 0 || ny < 0 || nx >= m || ny >= n || image[nx][ny] != image[sr][sc] || ans[nx][ny]==newColor)                         continue;
                    ans[nx][ny] = newColor;
                    rotten.push({nx, ny});
            }
        }
        
        return ans;
    }
};