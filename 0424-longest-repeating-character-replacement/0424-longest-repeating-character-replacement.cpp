class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int r=0;
        int maxlen=0;
        int maxf=0;
        int mp[26]={0};
        while(r<s.size())
        {
            mp[s[r]-'A']++;
            maxf=max(maxf,mp[s[r]-'A']);
            if(r-l+1-maxf > k)
            {
                mp[s[l]-'A']--;
                l++;
            }
                maxlen=max(maxlen,(r-l+1));
            r++;
        }
        return maxlen;
    }
};