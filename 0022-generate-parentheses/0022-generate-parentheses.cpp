class Solution {
public:
    void solve(string str,int n,int m,vector<string>&v){
        if(n==0 && m==0){
            v.push_back(str);
            return;
        }
        
            if(n>0)
                solve(str+"(",n-1,m,v);
            if(m>n)
                solve(str+")",n,m-1,v);
        
    }
    vector<string> generateParenthesis(int n) {
        string str="";
        vector<string>v;
        solve(str,n,n,v);
        return v;
    }
};
   
