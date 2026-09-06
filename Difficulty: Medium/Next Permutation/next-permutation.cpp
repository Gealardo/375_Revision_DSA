class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        int n=arr.size();
        int firstdip=-1;//from last
        for(int i=n-2; i>=0 ;i--){
            if(arr[i]<arr[i+1]) {
                firstdip=i; break;
            }
        }
        if(firstdip==-1){
           sort(arr.begin(),arr.end());
           return;
        } 
        
        for(int i=n-1;i>firstdip;i--){
            if(arr[i]>arr[firstdip]){
                swap(arr[i],arr[firstdip]);
                break;
            }
        }
        sort(arr.begin()+firstdip+1,arr.end());
        return;

    }
};