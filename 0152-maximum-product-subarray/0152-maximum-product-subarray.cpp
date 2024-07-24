class Solution {
public:
    int maxProduct(vector<int>& nums) {
       double res=nums[0],left=1,right=1;
       int n=nums.size()-1;
       for(int i=0 ;i<nums.size();i++)
       {
           left=left*nums[i];
           right=right*nums[n-i];
           res=max(res,max(left,right));
           if(left==0)left=1;
           if(right==0)right=1;
       }
       return res;
    }
};