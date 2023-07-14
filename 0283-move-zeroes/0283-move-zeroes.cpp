class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len=nums.size();
        int k=0;
        for(int i=0;i<len;i++)
        {
            if(nums[i]!=0)
            {
                nums[k]=nums[i];
                k++;
            }
        }
        for(int i=k;i<len;i++)
        {
            nums[i]=0;
        }
    }
};