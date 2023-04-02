class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<vector<int>>merge;
        if(intervals.size()==0)
            return merge;
        sort(intervals.begin(),intervals.end());
        int index=0;
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]<= intervals[index][1])
                intervals[index][1]=max(intervals[i][1],intervals[index][1]);
            else{
                index++;
                intervals[index]=intervals[i];
            }
        }
        cout<<index;
        for(int i=0;i<(n-index-1);i++)
        {
            intervals.pop_back();
        }
        return intervals;
            
    }
};