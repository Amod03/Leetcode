class Solution {
public:
    int arraySign(vector<int>& nums) {
        long long pro=1;
        int pos;
        int neg;
        pos=neg=0;
        int zero=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
                pos++;
            else if(nums[i]<0)
                neg++;
            else if(nums[i]==0)
                zero=1;
        }
        if(zero==1)
            return 0;
        else if(neg%2==0)
            return 1;
        else return -1;
    }
};