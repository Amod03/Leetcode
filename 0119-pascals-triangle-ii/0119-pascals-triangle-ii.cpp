class Solution {
public:
    vector<int> getRow(int n) {
        vector<int>v;
        long long res=1;
        for(int i=0;i<=n;i++)
        {
            if(i==0)
                v.push_back(1);
            else
            {
                res=res*(n-i+1);
                res=res/(i);
                v.push_back(res);
            }
        }
        return v;
    }
};