class Solution {
public:
    void solve(int index,int size,vector<vector<int>>& ans,vector<int>out,vector<int>& nums)
    {
        if(index>=size)
        {
            ans.push_back(out);
            return;
        }
        solve(index+1,size,ans,out,nums);
        out.push_back(nums[index]);
        solve(index+1,size,ans,out,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int size=nums.size();
        vector<vector<int>>ans;
        vector<int>out;
        solve(0,size,ans,out,nums);
        return ans;
    }
};