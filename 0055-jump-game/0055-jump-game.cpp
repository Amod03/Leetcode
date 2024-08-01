class Solution {
public:
    
    bool solve(int i,vector<int>&nums,vector<int>&dp){
        if(i==nums.size()-1){
            return true;
        }
        if(nums[i]==0){
            return false;
        }
        if(dp[i]!=-1)return dp[i];
        for(int j=1;j<=nums[i];j++){
            if(i+j<nums.size())
            if(solve(i+j,nums,dp))
                return dp[i]=true;
        }
        return dp[i]=false;
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(0,nums,dp);
    }
};