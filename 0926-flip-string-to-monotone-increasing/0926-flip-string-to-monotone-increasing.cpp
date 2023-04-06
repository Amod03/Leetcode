class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<int> pre;
        vector<int> suf;
        pre.push_back(0);
        suf.push_back(0);
        for(int i=1;i<=n;i++)
        {
            if(s[i-1]=='0')
                pre.push_back(pre[i-1]);
            else{
                int k=pre[i-1]+1;
                pre.push_back(k);
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='0')
                suf.push_back(suf[n-i-1]+1);
            else
                suf.push_back(suf[n-i-1]);
        }
        reverse(suf.begin(), suf.end());
        int ans = INT_MAX;
        for(int i=1;i<=n;i++)
        {
            int p = pre[i-1]+suf[i];
            ans=min(ans, p);
        }
        return ans;
    }
    
};