class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n=a.size();
     vector<int>dp(n,1),hash(n,0);
       
       for(int i=0;i<n;i++){
           hash[i]=i;
           for(int j=0;j<i;j++){
               if(a[j]<a[i] && 1+dp[j]>dp[i]){
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
        // printing
       // vector<int>order;
       // order.push_back(a[last_index]);
       // while(hash[last_index]!=last_index){
       //     last_index=hash[last_index];
       //     order.push_back(a[last_index]);
       // }
       // reverse(order.begin(),order.end());
    //   for(int i=0;i<order.size();i++){
    //       cout<<order[i]<<" ";
    //   }
       return maxi;
    }
};