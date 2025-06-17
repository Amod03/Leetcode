class Solution {
public:
    int countPrimes(int n) {
      vector<int>v(n+1);
      for(int i=0;i<=n;i++){
        v[i]=1;
      }

      for(int i=2;i*i<=n;i++){
        if(v[i]){
       for(int j=i*i;j<=n;j+=i){
        v[j]=0;
       }
        }
      }

    int count=0;

     for(int i=2;i<n;i++){
        if(v[i])
        count++;
    }
    return count;
    }
};