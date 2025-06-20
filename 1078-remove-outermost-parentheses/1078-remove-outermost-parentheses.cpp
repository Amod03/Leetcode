class Solution {
public:
    string removeOuterParentheses(string s) {
        string res="";
        int count = 0;
        for (char c : s) {
            if (c == ')') count--;
            if(count !=0 ) res=res+c;
            if(c == '(') count++;
        }
        return res;
    }
};