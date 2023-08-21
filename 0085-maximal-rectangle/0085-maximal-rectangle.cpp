class Solution {
  int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int maxA=0;
        int n=heights.size();
        for(int i=0;i<=n;i++)
        {
            while(!st.empty() && (i==n || heights[st.top()]>=heights[i]))
            {
                int height=heights[st.top()];
                st.pop();
                int width;
                if(st.empty()) width=i;
                else width=i-st.top()-1;
                maxA=max(maxA,width*height);
            }
            st.push(i);
        }
      return maxA;
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

