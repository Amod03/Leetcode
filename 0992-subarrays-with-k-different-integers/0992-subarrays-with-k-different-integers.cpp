class Solution {
public:
   int subarraysWithKDistinct(vector<int>& A, int K) {
        return atMostK(A, K) - atMostK(A, K - 1);
    }
    
    int atMostK(vector<int>& A, int K) {
        int l = 0, res = 0;
        int r=0;
        unordered_map<int, int> count;
        while(r<A.size()){
            count[A[r]]++;
            while (count.size() > K) {
               count[A[l]]--;
                if(count[A[l]]==0)
                    count.erase(A[l]);
                l=l+1;
            }
            res += r - l + 1;
            r++;
        }
        return res;
    }
};