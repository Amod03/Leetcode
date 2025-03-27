class Solution {
public:
    int missingNumber(vector<int>& a) {
      int len=a.size();
      int sum=len*(len+1);
      sum=sum/2;
      for(int i=0;i<len;i++){
        sum=sum-a[i];
      }
      return sum;
    }
};