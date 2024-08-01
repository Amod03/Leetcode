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
        vector<vector<vector<int>>>dp(m+2,vector<vector<int>>(n+2,vector<int>(maxMove+1,-1)));
        return solve(startRow+1,startColumn+1,m+1,n+1,maxMove,a,b,dp);
    }
};