class Solution {
    vector<int> nextsmall(vector<int>& arr,int n){
         stack<int> s;
        vector<int> ans(n,-1);
        for(int i=arr.size()-1;i>=0;i--){
           int curr=arr[i];
            while(!s.empty() && arr[s.top()]>=curr)
            {
            s.pop();
            }
            if(!s.empty())
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int> prevsmall(vector<int>& arr,int n){
         stack<int> s;
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
           int curr=arr[i];
            while(!s.empty() && arr[s.top()]>=curr)
            {
            s.pop();
            }
            if(!s.empty())
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int area=0;
        int n =heights.size();
        vector<int> next(n);
        vector<int> prev(n);
        next=nextsmall(heights,n);
        prev=prevsmall(heights,n);
        for(int i=0;i<n;i++){
            int l=heights[i];
            if(next[i]==-1)
            next[i]=n;
             int b=next[i]-prev[i]-1;
             int newarea=l*b;
             area=max(newarea,area);
        }
        return area;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
       // cout<<n<<endl;
        int m=matrix[0].size();
        int maxarea=0;
        //cout<<m<<endl;
        vector<int>hist(m,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='1')
                hist[j]++;
                else
                hist[j]=0;
            }
            int area=largestRectangleArea(hist);
            maxarea=max(area,maxarea);
        }
        return maxarea;
    }
};

