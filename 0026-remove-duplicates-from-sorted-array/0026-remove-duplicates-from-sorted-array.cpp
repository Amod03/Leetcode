class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
    int k=0;
    for(int i=0;i<arr.size();i++){
        if(arr[k]==arr[i]){
          continue;
        }else{
            k++;
            arr[k]=arr[i];
        }
    }
    return k+1;
    }
};