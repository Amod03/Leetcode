//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    int largestRectangleArea(int *heights,int n) {
        stack<int>st;
        int area=0;
        
        for(int i=0;i<=n;i++)
        {
            while(!st.empty() && (i==n || heights[st.top()]>=heights[i]))
            {
                int height=heights[st.top()];
                st.pop();
                int width;
                if(st.empty())
                width=i;
                else
                width=i-st.top()-1;
                area=max(area,width*height);
            }
            st.push(i);
        }
        return area;
    }
    int maxArea(int M[MAX][MAX], int n, int m) {
        int area=largestRectangleArea(M[0],m);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(M[i][j]!=0)
                M[i][j]=M[i][j]+M[i-1][j];
                else
                M[i][j]=0;
            }
            area=max(area,largestRectangleArea(M[i],m));
        }
        return area;
    }
};



//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends