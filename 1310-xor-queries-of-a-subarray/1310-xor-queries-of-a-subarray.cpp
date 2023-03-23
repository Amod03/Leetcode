class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>v;
        vector<int>pre;
        int len=arr.size();
        pre.push_back(arr[0]);
        for(int i=1;i<len;i++)
        {
            pre.push_back(pre[i-1]^arr[i]);
        }
        for(int i=0;i<len;i++)
        {
            cout<<pre[i]<<endl;
        }
        int rows=queries.size();
        for(int i=0;i<rows;i++)
        {
            int val1=queries[i][0];
            int val2=queries[i][1];
            if(val1==0)
                v.push_back(pre[val2]);
            else{
            
            int ans=pre[val2]^pre[val1-1];
            v.push_back(ans);
            }
        }
        return v;
    }
};