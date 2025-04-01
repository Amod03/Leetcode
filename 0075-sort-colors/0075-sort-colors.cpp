class Solution {
public:
    void sortColors(vector<int>& nums) {
       int low=0;
       int mid=0;
       int end=nums.size()-1;
       while(mid<=end){
        if(nums[mid]==2){
            swap(nums[end],nums[mid]);
            end--;
        }else if(nums[mid]==0){
            swap(nums[low],nums[mid]);
            low++;
            mid++;
        }else{
            mid++;
        }
       }
    }
};