class Solution {
public:
    int missingNumber(vector<int>& a) {
      int xor1=0,xor2=0;
        for(int i=0;i<a.size();i++){
            xor1=xor1^a[i];
            xor2=xor2^i;
        }
        return xor1^xor2^a.size();
    }
};