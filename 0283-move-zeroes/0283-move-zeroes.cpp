class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len=nums.size();
        int k=len;
        for(int i=0;i<len;i++){
            if(nums[i]==0){k=i;break;}
        }
        for(int i=k+1;i<len;i++){
            if(nums[i]!=0){
                int temp=nums[i];
                nums[k]=temp;
                nums[i]=0;
                k++;
            }
        }
        return;
    }
};