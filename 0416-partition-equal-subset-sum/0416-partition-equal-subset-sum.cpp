class Solution {
public:
    bool canPartition(vector<int>& arr) {
    int totSum=0;
    int n=arr.size();
    for(int i=0; i<n;i++){
        totSum+= arr[i];
    }
    
    if (totSum%2==1) return false;
    
    else{
        int k = totSum/2;
     vector<bool>prev(k+1,false);
        int n=arr.size();
    if (arr[0] <= k) {
        prev[arr[0]] = true;
    }
    for (int ind = 1; ind < n; ind++) {
        prev[0]=true;
        for (int target = k; target >=1; target--) {
            bool notTaken = prev[target];
            bool taken = false;
            if (arr[ind] <= target) {
                taken = prev[target - arr[ind]];
            }
            prev[target] = notTaken || taken;
        }
    }
    
    return prev[k];
    }
    }
};