class Solution {
public:
    int maximumCount(vector<int>& nums) 
    {
        //first we will find out the last occurence for the neg element
        int lastidx = -1;
        getlastidx(lastidx,nums);

        int firstidx = -1;
        getfirstidx(firstidx,nums);
        
        if(firstidx == -1 and lastidx == -1)
        {
            return 0;
        }
        if(lastidx == -1 or firstidx == -1)
        return nums.size();

        int neg = lastidx + 1;
        int pos = nums.size()-1 - firstidx + 1;

        return max(neg,pos);
    }
    void getfirstidx(int &firstidx,vector<int>&nums)
    {
        int start = 0;
        int end = nums.size()-1;

        while(start <= end)
        {
            int mid = (start + end)/2;
            
            if(nums[mid] <= 0)
            {
                start = mid+1;
            }
            else if(nums[mid] > 0)
            {
                firstidx = mid;
                end = mid-1;
            }
        }
    }
    void getlastidx(int &lastidx,vector<int>&nums)
    {
        int start = 0;
        int end = nums.size()-1;

        while(start <= end)
        {
            int mid = (start+end)/2;

            if(nums[mid]>=0)
            {
                end = mid-1;
            }
            else if(nums[mid]<0)
            {
                lastidx = mid;
                start = mid+1;
            }
        }
    }
};