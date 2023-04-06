class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& num, int target) {
        vector<vector<int>>res;
        if(num.size()==0)
            return res;
        
        int n=num.size();
        sort(num.begin(),num.end());
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                long long target_2=target-num[i];
                target_2=target_2-num[j];
                int front=j+1;
                int back=n-1;
                
                while(front<back)
                {
                    long long two_sum=num[front]+num[back];
                    if(two_sum<target_2)
                        front++;
                    else if(two_sum>target_2)
                        back--;
                    else{
                        vector<int>quad;
                        quad.push_back(num[i]);
                        quad.push_back(num[j]);
                        quad.push_back(num[front]);
                        quad.push_back(num[back]);
                        res.push_back(quad);
                        
                        while(front<back && num[front]==num[front+1])
                            ++front;
                        while(front<back && num[back]==num[back-1])
                        --back;
                        front++;
                        back--;
                    }
                }
                while(j+1<n && num[j+1]==num[j])
                    j++;
                
            }
            while(i+1<n && num[i+1]==num[i])
                ++i;
        }
        return res;
    }
};