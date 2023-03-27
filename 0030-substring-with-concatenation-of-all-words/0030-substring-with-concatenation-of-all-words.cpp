class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>ans;
        if(s.length()==0 || words.size()==0 || words.size()*words[0].length()>s.length())
            return ans;
        unordered_map<string,int>wordsfreq;
        for(int i=0;i<words.size();i++)
        {
            wordsfreq[words[i]]++;
        }
        int n=words.size();
        int l=words[0].length();
        unordered_map<string,int>temp;
        for(int i=0;i<=s.length()-n*l;i++)
        {
            for(int j=i;j<i+n*l;j+=l)
            {
                temp[s.substr(j,l)]++;
            }
            int flag=1;
            for(int j=0;j<n;j++)
            {
                if(temp.find(words[j])==temp.end() || temp[words[j]]!=wordsfreq[words[j]])
                {
                    flag=0;
                    break;
                }
            }
                if(flag==1)
                    ans.push_back(i);
                temp.clear();
        }
        return ans;
    }
};

//T.C.->(N-n*l)(2*n*l)==>(N-n*l)(n*l)
//S.C->(n*l)