class Solution {
  public:
    int search(vector<int>& arr, int key) {
        int n=arr.size();
        int l=0;
        int h=n-1;
        while(l<=h){
            int m=l+(h-l)/2;
            if(arr[m]==key) return m;
            if(arr[l]<=arr[m]){
                if(arr[l]<=key && arr[m]>key){
                    h=m-1;
                }
                else l=m+1;
            }
            else {
                if(arr[m]<key && arr[h]>=key){
                    l=m+1;
                }
                else h=m-1;
            }
        }
        return -1;
        
    }
};