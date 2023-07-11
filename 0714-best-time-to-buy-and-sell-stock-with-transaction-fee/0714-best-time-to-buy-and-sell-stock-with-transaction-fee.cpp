class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<int>front1(2,0);
        vector<int>cur(2,0);
        for(int ind=n-1;ind>=0;ind--)
        {
            cur[1]=max(-prices[ind]+front1[0]-fee,0+front1[1]);
            cur[0]=max(prices[ind]+front1[1],0+front1[0]);
            front1=cur;
        }
        return cur[1];
    }
};