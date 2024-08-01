class Solution {
public:
    
    int solve(int iR,int jC,int m,int n,int move,int a[],int b[],vector<vector<vector<int>>>&dp){
        if(iR == 0 || iR ==m || jC==0 || jC==n){
                  return 1;
         }
        if(move==0)
            return 0;
        if(dp[iR][jC][move]!=-1 )return dp[iR][jC][move];
        int ways=0;
        for(int i=0;i<4;i++){
                int newR=iR-a[i];
                int newC=jC-b[i];
                ways=(ways + solve(newR,newC,m,n,move-1,a,b,dp))%(1000000007);
        }
        
        return dp[iR][jC][move]=ways;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int a[]={-1,0,1,0};
        int b[]={0,1,0,-1};
        vector<vector<vector<int>>>dp(m+2,vector<vector<int>>(n+2,vector<int>(maxMove+1,0)));
         const int MOD = 1000000007;

        for(int i=0;i<n+2;i++){
            for(int j=0;j<=maxMove;j++){
                dp[0][i][j]=1;
            }
        }
        for(int i=0;i<m+2;i++){
            for(int j=0;j<=maxMove;j++){
                dp[i][0][j]=1;
            }
        }
        for(int i=0;i<n+2;i++){
            for(int j=0;j<=maxMove;j++){
                dp[m+1][i][j]=1;
            }
        }
        for(int i=0;i<m+2;i++){
            for(int j=0;j<=maxMove;j++){
                dp[i][n+1][j]=1;
            }
        }
        
        int ways=0;
        for (int move = 1; move <= maxMove; ++move) {
            for (int i = 1; i <= m; ++i) {
                for (int j = 1; j <= n; ++j) {
                    for (int k = 0; k < 4; ++k) {
                        int newR = i + a[k];
                        int newC = j + b[k];
                        dp[i][j][move] = (dp[i][j][move] + dp[newR][newC][move - 1]) % MOD;
                    }
                }
            }
        }

        return dp[startRow+1][startColumn+1][maxMove];
    }
};