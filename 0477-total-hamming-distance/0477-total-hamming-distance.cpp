class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
     int n=nums.size();
        int ans=0;
        long mask=1L<<31;
        for(int i=31;i>=0;i--)
        {
            int count=0;
            for(int j=0;j<n;j++)
            {
                if(mask & nums[j])
                    count++;
            }
            ans=ans+(count*(n-count));
            mask>>=1;
        }
        return ans;
    }
};