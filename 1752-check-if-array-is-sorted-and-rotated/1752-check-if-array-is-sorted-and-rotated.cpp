class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int pivot=0;
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]>nums[i+1])
                pivot=i+1;
        }
        cout<<pivot;
        for(int i=0;i<n-1;i++)
        {
            if(nums[(pivot+i)%n]>nums[(pivot+i+1)%n])
                return false;
        }
        return true;
    }
};