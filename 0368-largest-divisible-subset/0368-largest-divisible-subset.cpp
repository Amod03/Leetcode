class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& a) {
        int n=a.size();
        sort(a.begin(),a.end());
     vector<int>dp(n,1),hash(n,0);
       
       for(int i=0;i<n;i++){
           hash[i]=i;
           for(int j=0;j<i;j++){
               if(a[i]%a[j]==0 && 1+dp[j]>dp[i]){
                   dp[i]=1+dp[j];
                   hash[i]=j;
               }
           }
       }
       int maxi=INT_MIN;
       int last_index=-1;
       for(int i=0;i<n;i++){
           if(dp[i]>maxi){
               maxi=dp[i];
               last_index=i;
           }
       }
       vector<int>order;
       order.push_back(a[last_index]);
       while(hash[last_index]!=last_index){
           last_index=hash[last_index];
           order.push_back(a[last_index]);
       }
       return order;
    }
};