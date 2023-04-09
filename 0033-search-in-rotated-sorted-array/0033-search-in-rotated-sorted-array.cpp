class Solution {
public:
    int getpivot(vector<int>&arr,int n)
    {
        int s=0;
        int e=n-1;
        while(s<e)
        {
            int mid=s+(e-s)/2;
            if(arr[mid]>=arr[0])
            s=mid+1;
            else
            e=mid;
        }
        return s;
    }
     
    int binarysearch(vector<int>&arr,int s,int e,int key)
    {
        int start=s;
        int end=e;
        while(start<=end)
        {
          int mid=start+(end-start)/2;
          if(arr[mid]==key)
          return mid;
          else if(arr[mid]>key)
          end=mid-1;
          else
          start=mid+1;
        }
        return -1;
    } 


    int search(vector<int>& nums, int target) {
        int pivot=getpivot(nums,nums.size());
        if(target>=nums[pivot] && target<=nums[nums.size()-1] )
         return binarysearch(nums,pivot,nums.size()-1,target);
         else
        return binarysearch(nums,0,pivot-1,target);
        

    }
};