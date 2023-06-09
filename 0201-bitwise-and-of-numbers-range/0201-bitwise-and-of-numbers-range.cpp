class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        long mask=1L<<31;
        long ans=0;
        while(mask)
        {
            if((mask&left) == (mask&right))
            {
                if(mask & left)
                ans=ans+mask;
                mask=mask>>1;
            }
            else 
                break;
        }
        return ans;
    }
};