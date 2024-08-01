class Solution {
public:
    double solve(int iR,int jC,int n,int move,int a[],int b[],vector<vector<vector<double>>>& dp){
        if(iR < 0 || iR >=n || jC<0 || jC>=n){
                  return 0;
         }
        if(move==0)
            return 1;
        if(dp[move][iR][jC]!=-1 )return dp[move][iR][jC];
        double ways=0.0;
        for(int i=0;i<8;i++){
                int newR=iR+a[i];
                int newC=jC+b[i];
                ways+=(solve(newR,newC,n,move-1,a,b,dp))/8;
        }
        
        return dp[move][iR][jC] = ways;
    }
    
    double knightProbability(int n, int k, int row, int column) {
        int a[]={-2,-1,1,2,2,1,-1,-2};
        int b[]={1,2,2,1,-1,-2,-2,-1};
        vector<vector<vector<double>>> dp(k+1, vector<vector<double>>(n, vector<double>(n, 0)));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dp[0][i][j]=1;
            }
        }
        
        for (int move = 1; move <= k; ++move) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    for (int k = 0; k < 8; ++k) {
                        int iR = i + a[k];
                        int jC = j + b[k];
                        if(iR < 0 || iR >=n || jC<0 || jC>=n){
                              continue;
                          }else{
                        dp[move][i][j] = (dp[move][i][j] + dp[move-1][iR][jC]/8);         
                        }
                    }
                }
            }
        }

        return dp[k][row][column];
    }
};