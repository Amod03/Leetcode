class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count = 0, n = start ^ goal;
        while(n){
            n &= (n - 1);
            count++;
        }
        return count;
    }
};