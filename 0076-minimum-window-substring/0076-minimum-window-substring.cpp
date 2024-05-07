class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(128,0);
        for (char c : t) {
            map[c]++;
        }
        int counter=0;
        int ssize = t.size(), begin = 0, end = 0, d = INT_MAX, head = 0;
        while (end < s.size()){
            if (map[s[end]] > 0) {
                counter++;
            }
            map[s[end]]--;
            while (counter == ssize ) {
                if(end-begin+1 < d)
                {
                    d=end-begin+1;
                    head=begin;
                }
                map[s[begin]]++;
                if(map[s[begin]]>0)
                    counter--;
                    begin++;
                }
            end++;
            }  
        
        return d == INT_MAX ? "" : s.substr(head, d);
    }
};