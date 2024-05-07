class Solution {
public:
    int numberOfSubstrings(string s) {
         int count[3] = {-1, -1, -1},res = 0 , n = s.length();
        for (int j = 0; j < n; ++j) {
            count[s[j] - 'a']=j;
            if(count[0] != -1 && count[1] !=-1 && count[2] !=-1){
                int mini=min(count[0],count[1]);
                res=res+1+min(mini,count[2]);
            }

            }
        return res;
    }
};