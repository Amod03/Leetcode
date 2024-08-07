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
        // int n=nums.size();
        // vector<int>dp(n,0);
        // dp[n-1]=1;
        // for(int i=n-1;i>=0;i--){
        //    for(int j=1;j<=nums[i];j++){
        //      if(i+j<nums.size())
        //      if(dp[i+j])
        //        dp[i]=1;
        // }
        // }
        // return dp[0];
        
        //it shows at max what index can I reach.
        //initially I can only reach index 0, hence reach = 0
        int reach = 0; 
    
        for(int idx = 0; idx < nums.size(); idx++) {
            if(idx > reach) return false;
            reach = max(reach, idx + nums[idx]);
        }
        return true;
    }
};