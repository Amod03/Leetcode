class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int len=arr.size();
        if(len==0)
            return 0;
        
        int i=0;
        for(int j=1;j<len;j++)
        {
            if(arr[i]!=arr[j])
            {
                i++;
                arr[i]=arr[j];
            }
        }
        return i+1;
    }
};