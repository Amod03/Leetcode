class Solution {
public:
    int solve(int i,int prev,vector<int>&nums,vector<vector<int>>&dp){
        if(i==nums.size())
            return 0;
        int take=0;
        int nottake=0;
        if(dp[i][prev+1]!=-1)return dp[i][prev+1];
        if(prev==-1 || nums[i]>nums[prev])
            take=1+solve(i+1,i,nums,dp);
        
            nottake=solve(i+1,prev,nums,dp);
        
        return dp[i][prev+1]=max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>prev(n+1,0);
        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--){
                int take=0;
                int nottake=0;
            if(j==-1 || nums[i]>nums[j])
            take=1+prev[i+1];
        
            nottake=prev[j+1];
        
        prev[j+1]=max(take,nottake);
            }
        }
        return prev[0];
    }
};