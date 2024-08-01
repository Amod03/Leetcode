class Solution {
public:
    int solve(int i,vector<int>&nums,vector<int>&dp){
        if(i==nums.size()-1){
            return 0;
        }
        if(nums[i]==0){
            return 1e9;
        }
        if(dp[i]!=-1)return dp[i];
        int mini=INT_MAX;
        for(int j=1;j<=nums[i];j++){
            if(i+j<nums.size())
            mini=min(mini,1+solve(i+j,nums,dp));      
        }
        return dp[i]=mini;
    }
    
    int jump(vector<int>& nums) {
        int n=nums.size();
        int l,r,jump;
        l=r=jump=0;
        while(r<n-1){
          int farthest=0;
          for(int i=l;i<=r;i++){
              farthest=max(farthest,i+nums[i]);
          }
            l=r+1;
            r=farthest;
            jump++;
        }
        return jump;
    }
};
