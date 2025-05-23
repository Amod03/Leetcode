class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      int sum=0;
      unordered_map<int,int>mp;
      int count=0;
      for(int i=0;i<nums.size();i++){
        sum=sum+nums[i];
        if(sum == k)
            count++;
            count=count+mp[sum-k];
        mp[sum]++;
      }
      return count;
    }
};