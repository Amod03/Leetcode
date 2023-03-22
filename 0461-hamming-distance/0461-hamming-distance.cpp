class Solution {
public:
    int hammingDistance(int x, int y) {
        int Xor = x ^ y, ans = 0;
        while(Xor) {
            ans++,
            Xor &= Xor-1;
        }
        return ans;
    }
};