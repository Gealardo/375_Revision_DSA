class Solution {
  public:
    int stockBuySell(vector<int> &arr) {
        int n=arr.size();
        if(n<2) return 0;
        int profit=0;
        for(int i=1;i<n;i++){
            if(arr[i-1]<arr[i]) profit+=arr[i]-arr[i-1];
        }
         return profit;
    } 
};
