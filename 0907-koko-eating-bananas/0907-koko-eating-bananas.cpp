class Solution {
public:
    bool check(vector<int>piles,int h,int size,int mid)
    {
        int count=0;
        for(int i=0;i<size;i++)
        {
          count=count+(piles[i]/mid)+(piles[i]%mid!=0);
          if(count>h)
          return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=*max_element(piles.begin(),piles.end());
        int low=1;
        int high=maxi;
        int ans=high;
        while(low<=high)
        {
         int mid=(low+high)/2;
         if(check(piles,h,piles.size(),mid))
         {
             high=mid-1;
         }
         else
           low=mid+1;
        }
        return low;
    }
};