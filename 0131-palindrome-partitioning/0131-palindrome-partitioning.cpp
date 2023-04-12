class Solution {
public:
vector<vector<string>>ans;
 bool isP(string& s,int i,int j)
    {
       while(i<j)
       {
           if(s[i]!=s[j])
           return 0;
           i++;
           j--;
       }
       return 1;
    }
   void perm(string &s,int in,vector<string>& v)
   {
    if(in==s.size())
    {
    ans.push_back(v);
    return ;
    }
    for(int j=in;j<s.size();j++)
    {
        if(isP(s,in,j))
        {
            v.push_back(s.substr(in,j-in+1));
            perm(s,j+1,v);
            v.pop_back();
        }
    }
   }
   
    vector<vector<string>> partition(string s) {
        vector<string>v;
        perm(s,0,v);
        return ans;
    }
};