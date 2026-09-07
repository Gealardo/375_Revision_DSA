class Solution {
  public:
    int findEquilibrium(vector<int> &arr) {
    // prefix sum pattern    
       int n=arr.size(); 
       if(n==0) return -1;
       vector<int>prefixsum(n);
       prefixsum[0]=arr[0];
       for(int i=1;i<n;i++){
           prefixsum[i]=prefixsum[i-1]+arr[i];
       }
       for(int i=0;i<n;i++){
           int leftsum=  (i==0)?   0 : prefixsum[i-1];
           int rightsum=(i==n-1)?  0 : prefixsum[n-1]-prefixsum[i];
           
           if(leftsum==rightsum) return i;
       }
       return -1;    
    }
};
