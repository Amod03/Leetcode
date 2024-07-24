class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int len=nums.size();
       int k=-1;
       for(int i=0;i<len;i++){
           if(nums[i]==0){
               k=i;
               break;
           }
       }
        if(k==-1){
            return;
        }
        int temp=k;
        for(int i=k+1;i<len;i++){
          if(nums[i]!=0){
              swap(nums[temp],nums[i]);
              temp++;
          }  
        }
        return;
    }
};