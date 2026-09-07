class Solution {
  public:
    int maxWater(vector<int> &arr) {
       int n=arr.size();
       if(n==0 || n==1) return 0;
       int l=0;
       int r=n-1;
       int area=0;
       while(l<r){
           int bottle_neck_h = min(arr[l],arr[r]);
           int w = r-l;
           int capacity = bottle_neck_h * w;
           area=max(area,capacity);
           if(arr[l]==bottle_neck_h) l++;
           else r--;
       }
       return area;
    }
};