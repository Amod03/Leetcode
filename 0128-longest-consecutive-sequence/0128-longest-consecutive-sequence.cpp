class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>mp;
        int size=nums.size();
        for(int i=0;i<size;i++)
        {
            mp[nums[i]]=1;
        }
        int ans=0;
        for(int i=0;i<size;i++)
        {
            if(mp.find(nums[i]-1)!=mp.end())
                continue;
            //if(visited.find(nums[i])!=visited.end())
              //  continue;
            //visited[nums[i]]=1;
            int len=0;
            int x=nums[i];
            while(mp.find(x)!=mp.end())
            {
               len++;
                x++;
            }
            ans=max(ans,len);
        }
        return ans;
    }
};
