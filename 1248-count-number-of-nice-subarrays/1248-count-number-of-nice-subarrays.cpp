class Solution {
public:
     int atmostSubarray(vector<int>&nums, int goal)
    {
        //checking if the goal is negative
        //then return 0 as sum can't be negative
        //0's and 1's are there in the array.
        if(goal<0)
            return 0;
        int sum=0; // For calculating the current sum
        int i=0;
        int j=0;
        int res=0; // storing the res
        while(j<nums.size())
        {
            //we're iterating over the nums array and 
            //then adding the current element into the sum
            sum+=nums[j]; 
            
            //if our current sum is greater than our goal
            //that means we don't need the extra element
            //so we will shrink our window by subtracting 
            //the ith elements from sum till sum > goal
            while(sum>goal)
            {
                sum-=nums[i];
                i++;
            }
            //We're adding the length of each subarray 
            //to our result
            res+=(j-i+1);
            
            j++;
        }
        
        return res;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i= 0;i<nums.size();i++)
        {
            nums[i]=nums[i]%2;
        }
     return atmostSubarray(nums,k)-atmostSubarray(nums,k-1);   
    }
};