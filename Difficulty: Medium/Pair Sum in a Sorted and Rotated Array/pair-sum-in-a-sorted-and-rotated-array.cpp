class Solution {
  public:
    int find_firstpeek(vector<int>& arr){
        int n=arr.size();
        int firstpeek=-1;
        for(int i=n-2;i>=0;i--){
            if(arr[i]>arr[i+1]){
                firstpeek=i;
                break;
            }
        }
        return firstpeek;
    }
    
    bool pairInSortedRotated(vector<int>& arr, int target) {
       int n=arr.size();    
       int high=(find_firstpeek(arr)!=-1)? find_firstpeek(arr):n-1 ;
       int low=(high+1)%n;
       while(low!=high){
           int sum=arr[low]+arr[high];
           if(sum==target) return true;
           else if(sum<target) low=(low+1)%n;
           else high = (high-1+n)%n;
       }
       return false;
     
    }
};