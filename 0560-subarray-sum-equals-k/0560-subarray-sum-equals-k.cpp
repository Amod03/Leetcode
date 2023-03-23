class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int psum=0;
        m[psum]=1;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            psum=psum+nums[i];
            
            if(m.find(psum-k)!=m.end())
            {
                count=count+m[psum-k];
            }
                m[psum]++;
        }
        return count;
        
    }
};