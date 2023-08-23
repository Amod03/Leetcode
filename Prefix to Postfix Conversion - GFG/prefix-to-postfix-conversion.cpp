//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   bool isChar(char ch){
        if(ch == '+' ||ch == '-' ||ch == '*' ||ch == '/' ){
            return false;
        }
        return true;
    }

    string preToPost(string s) {  
        stack<string> st;
        reverse(s.begin(),s.end());
        for(int i = 0 ; i<s.size();i++){
            if(isChar(s[i])){
                string curr(1,s[i]);
                st.push(curr);
            }
            else{
                string first = st.top();
                st.pop();
                string second = st.top();
                st.pop();
                first = first+second+s[i];
                st.push(first);
            }
        }
        string ans = st.top();
        st.pop();
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToPost(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends