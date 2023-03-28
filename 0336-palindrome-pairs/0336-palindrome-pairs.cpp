class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
         unordered_map<string, int> umap;

        for(int i=0; i<words.size(); i++){

            string rev = string(words[i].rbegin(), words[i].rend());

            umap[rev] = i;

        }

        map<pair<int, int>, bool> m;

        vector<vector<int>> ans;

        

        for(int i=0; i<words.size(); i++){

            if(umap.find("") != umap.end() and umap[""] != i and isPalindrome(words[i], 0, words[i].size()-1) and m.find({i, umap[""]}) == m.end()){

                m[{i,umap[""]}] = true;

                m[{umap[""],i}] = true;

                ans.push_back({i, umap[""]});

                ans.push_back({umap[""], i});

            }

            

            string prefix;

            for(int j=0; j<words[i].size(); j++){

                prefix = words[i].substr(0,j+1);

                if(umap.find(prefix) != umap.end() and umap[prefix] != i and isPalindrome(words[i], j+1, words[i].size()-1) and m.find({i, umap[prefix]}) == m.end()){

                    m[{i, umap[prefix]}] = true;

                    ans.push_back({i,umap[prefix]});

                }

            }

            

            string suffix;

            for(int j=words[i].size()-1; j>=0; j--){

                suffix = words[i].substr(j,words[i].size()-j);

                if(umap.find(suffix) != umap.end() and umap[suffix] != i and isPalindrome(words[i], 0,j-1) and m.find({umap[suffix], i}) == m.end()){

                 m[{umap[suffix], i}] = true;

                    ans.push_back({umap[suffix], i});

                }

            }

        }

        return ans;

        

    }

    

    bool isPalindrome(string &s, int i, int j){

        while(i<j){

            if(s[i] != s[j]){

                return false;

            }

            i++;

            j--;

        }

        return true;

    }
};