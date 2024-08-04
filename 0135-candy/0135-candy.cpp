class Solution {
public:
    int candy(vector<int>& ratings) {
         int n = ratings.size();
        int sum = 1, i=1;
        while(i<n){
            if(ratings[i] == ratings[i-1]){
                i++;
                sum++;
                continue;
            }
            
            //For increasing slope
            int peak = 1;
            while(i<n && ratings[i] > ratings [i-1]){
                peak++;
                sum += peak;
                i++;
                
            }
            
            //For decreasing slope
            int valley = 1;
            while(i<n && ratings[i] < ratings[i-1]){
                sum += valley;
                valley++;
                i++;
            }
            if(valley>peak)
                sum=sum+valley-peak; //Keep only the higher peak
        }
        return sum;
    }
};