class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>v(n,0);
        int even=0;
        int odd=1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<0)
            {
                v[odd]=nums[i];
                odd=odd+2;
            }
            else{
                v[even]=nums[i];
                even=even+2;
            }
        }
        return v;
    }
};