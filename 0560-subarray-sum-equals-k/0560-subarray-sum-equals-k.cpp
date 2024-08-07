class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int sum=0;
        mp[0]=1;
        int count=0;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
            int diff=sum-k;
            count=count+mp[diff];
            mp[sum]++;
        }
        return count;
    }
};