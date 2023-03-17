class Solution {
public:
    vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ret;
	for (int i = 0; i < numRows; i++) {
		vector<int> row;
		for (int j = 0; j <= i; j++) {
            if(j==0||j==i)
                row.push_back(1);
            else
			row.push_back( ret[i - 1][j] + ret[i - 1][j - 1]);
		}
		ret.push_back(row);
	}
	return ret;
    }
};