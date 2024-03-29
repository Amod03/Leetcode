class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		//vector<int>v;
		int n=nums.size();
		int start=0, end=n-1, start1=0, end1=n-1, first=-1, last=-1;
		while(start<=end){
			int mid=start+(end-start)/2;
			if(target==nums[mid]){
				first=mid;
				end=mid-1;  //searching element in the leftmost part for the first most occurence
			}
			if(target>nums[mid]){
				start=mid+1;
			}
			else if(target<nums[mid]){
				end=mid-1;
			}

		}
		if(first==-1){
			return {-1,-1};
		}
		else{
		while(start1<=end1){
			int mid=start1+(end1-start1)/2;
			if(target==nums[mid]){
				last=mid;
				start1=mid+1; //searching elemnt in the rightmost part for last occurence
			}
			else if(target>nums[mid]){
				start1=mid+1;
			}
			else if(target<nums[mid]){
				end1=mid-1;
			}

		}
		return {first,last};
        }
	}
};