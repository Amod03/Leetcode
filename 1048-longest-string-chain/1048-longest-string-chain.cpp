class Solution {
public:
    bool compare(string& s1, string& s2){
    if(s1.size() != s2.size() + 1) return false;
    
    int first = 0;
    int second = 0;
    
    while(first < s1.size()){
        if(second < s2.size() && s1[first] == s2[second]){
            first ++;
            second ++;
        }
        else first ++;
    }
    if(first == s1.size() && second == s2.size()) return true;
    else return false; 
}
    
    static bool comp(string& s1, string& s2){
    return s1.size() < s2.size();
}
    
    int longestStrChain(vector<string>& a) {
         int n=a.size();
      sort(a.begin(), a.end(),comp);
     vector<int>dp(n,1),hash(n,0);
       
       for(int i=0;i<n;i++){
           hash[i]=i;
           for(int j=0;j<i;j++){
               if(compare(a[i], a[j]) && 1+dp[j]>dp[i]){
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
 vector<string>order;
       order.push_back(a[last_index]);
       while(hash[last_index]!=last_index){
           last_index=hash[last_index];
           order.push_back(a[last_index]);
       }
       reverse(order.begin(),order.end());
      for(int i=0;i<order.size();i++){
          cout<<order[i]<<" ";
      }
       return maxi;
    }
};