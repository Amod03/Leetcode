class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
         int n=prices.size();
        vector<int>prev(k*2+1,0),cur(k*2+1,0);
        for(int i=n-1;i>=0;i--){
            for(int transaction=0;transaction<k*2;transaction++){
            if(transaction%2==0)
        prev[transaction]=max(cur[transaction+1]-prices[i],cur[transaction]);
        else
        prev[transaction]=max(cur[transaction+1]+prices[i],cur[transaction]);
            }
            cur=prev;
        }
        return cur[0];
    }
};