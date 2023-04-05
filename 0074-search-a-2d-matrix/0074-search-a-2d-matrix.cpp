class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0)
            return false;
        
        int n=matrix.size();
        int m=matrix[0].size();
        
        int lo=0;
        int high=(n*m)-1;
        while(lo<=high)
        {
            int mid=(lo+(high-lo)/2);
            if(matrix[mid/m][mid%m]==target)
                return true;
            else if(matrix[mid/m][mid%m]<target)
                lo=mid+1;
            else
                high=mid-1;
        }
        return false;
    }
};