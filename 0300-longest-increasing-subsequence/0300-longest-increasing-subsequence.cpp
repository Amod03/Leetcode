class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
     vector<int> dp(n,1);
    for(int i=0; i<=n-1; i++){
        for(int prev_index = 0; prev_index <i; prev_index ++){
            
            if(nums[prev_index]<nums[i]){
                dp[i] = max(dp[i], 1 + dp[prev_index]);
            }
        }
    }
    int ans = -1;
    for(int i=0; i<=n-1; i++){
        ans = max(ans, dp[i]);
    }
    return ans;
    }
};