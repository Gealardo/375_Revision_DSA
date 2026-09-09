class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int n=arr.size();
        
        vector<int>left_max(n);
        left_max[0]=0;
        for(int i=1;i<n;i++){
            left_max[i] = max(arr[i-1] , left_max[i-1]);
        }
        
        vector<int>right_max(n);
        right_max[n-1]=0;
        for(int i=n-2;i>=0;i--){
            right_max[i] = max(right_max[i+1], arr[i+1]);
        }
        
        // calculate rain water
        int water = 0;
        for(int i=0;i<n;i++){
            int h=min(left_max[i],right_max[i]);
            if(h-arr[i]>=0){
                water += h-arr[i];
            }
        }
      return water;    
    }
};