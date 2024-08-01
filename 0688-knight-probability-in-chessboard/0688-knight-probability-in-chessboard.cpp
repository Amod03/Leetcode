class Solution {
public:
    double solve(int iR,int jC,int n,int move,int a[],int b[],vector<vector<vector<double>>>& dp){
        if(iR < 0 || iR >=n || jC<0 || jC>=n){
                  return 0;
         }
        if(move==0)
            return 1;
        if(dp[iR][jC][move]!=-1 )return dp[iR][jC][move];
        double ways=0.0;
        for(int i=0;i<8;i++){
                int newR=iR+a[i];
                int newC=jC+b[i];
                ways+=(solve(newR,newC,n,move-1,a,b,dp))/8;
        }
        
        return dp[iR][jC][move] = ways;
    }
    
    double knightProbability(int n, int k, int row, int column) {
        int a[]={-2,-1,1,2,2,1,-1,-2};
        int b[]={1,2,2,1,-1,-2,-2,-1};
        vector<vector<vector<double>>> dp(n, vector<vector<double>>(n, vector<double>(k+1, -1)));

        return solve(row,column,n,k,a,b,dp);
    }
};
// double count(int n, int k, int i, int j, vector<vector<vector<double>>>& dp)
// {
//     if(i >= n || j >= n || i < 0 || j < 0) {return 0;}
//     if(k == 0) {return 1;}

//     if(dp[k][i][j] != -1) {return dp[k][i][j];}
    
//     double dx[] = {1,1,2,2,-1,-1,-2,-2};
//     double dy[] = {2,-2,1,-1,2,-2,1,-1};
    
//     double safe = 0;
//     for(int l = 0; l < 8; l++)
//     {
//         int x = i + dx[l];
//         int y = j + dy[l];
//         safe += (count(n,k-1,x,y,dp)/8); 
//     }

//     return dp[k][i][j] = safe;
// }

// double knightProbability(int n, int k, int row, int column) 
// {
//    vector<vector<vector<double>>> dp(k+1, vector<vector<double>>(n, vector<double>(n, -1)));
//     double safeProb = count(n,k,row,column, dp);
//     return safeProb;
// }