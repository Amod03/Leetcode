#include<bits/stdc++.h>
class Solution {
public:
    int maxDepth(string s) {
        int count=0;
        int maxi=INT_MIN;
        for(int i=0;i<s.length();i++){
            if(s[i] == '('){
                count++;
            }
            if(s[i]==')'){
                count--;
            }
            maxi=max(maxi,count);
        }
        return maxi;
    }
};