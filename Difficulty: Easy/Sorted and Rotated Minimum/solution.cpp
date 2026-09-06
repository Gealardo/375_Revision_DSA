class Solution {
  public:
    int findMin(vector<int>& arr) {
        int n=arr.size();
        int l=0;
        int h=n-1;
        int mini=INT_MAX;
        while(l<=h){
            int m=l+(h-l)/2;
            if(arr[l]<=arr[m] && arr[m]<=arr[h]){
                if(arr[l]<mini){
                    mini=arr[l];
                }
                break;
            }
            else if(arr[l]<=arr[m]){
                if(arr[l]<mini){
                    mini=arr[l];
                }
                l = m+1;
            }
            else{
                if(arr[m]<mini){
                    mini=arr[m];
                }
                h = m-1;
            }
        }
        return mini;
    }
};
