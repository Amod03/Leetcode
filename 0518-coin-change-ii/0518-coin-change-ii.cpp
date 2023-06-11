class Solution {
public:
    int change(int target, vector<int>& coins) {
        int n=coins.size();
        vector<int>prev(target+1,0),cur(target+1,0);
        
        for(int t=0;t<=target;t++)
        {
            if(t%coins[0]==0)
                prev[t]=(t%coins[0]==0);
        }
        for(int ind=1;ind<n;ind++)
        {
            for(int t=0;t<=target;t++)
            {
                int nottake=prev[t];
                int take=0;
                if(coins[ind]<=t)
                {
                    take=cur[t-coins[ind]];
                }
                cur[t]=take+nottake;
            }
            prev=cur;
        }
        int ans=prev[target];
        return ans;
    }
};