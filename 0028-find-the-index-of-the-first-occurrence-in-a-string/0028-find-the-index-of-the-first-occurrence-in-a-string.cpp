class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i=0;i<haystack.length();i++)
        {
            int j=i;
            int ptr=0;
            int count=0;
            while(haystack[j]==needle[ptr] && ptr<needle.length())
            {
                j++;
                ptr++;
                count++;
            }
            if(count==needle.length()) return i;
        }
        return -1;
    }
};