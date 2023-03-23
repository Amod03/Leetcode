class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size();
        int totalXOR=0;
        for(int i=0;i<n;i++)
        {
            totalXOR=totalXOR^nums[i];
        }
        int leastSetBit=1;
        while(!(leastSetBit & totalXOR))
            leastSetBit<<=1;
        int val1=0;
        for(int i=0;i<n;i++)
        {
            if(leastSetBit & nums[i])
                val1=val1^nums[i];
        }
        int val2=totalXOR^val1;
        vector<int>v;
        v.push_back(val1);
        v.push_back(val2);
        return v;
    }
};