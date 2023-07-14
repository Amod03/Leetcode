class Solution {
public:
    int missingNumber(vector<int>& a) {
        int xor1 = 0, xor2 = 0;
    int N=a.size();
    for (int i = 0; i < N ; i++) {
        xor2 = xor2 ^ a[i]; 
        xor1 = xor1 ^ (i ); 
    }
    xor1 = xor1 ^ N; 

    return (xor1 ^ xor2);
    }
};