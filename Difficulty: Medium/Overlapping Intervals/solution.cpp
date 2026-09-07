class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
       int n=arr.size();
       vector<vector<int>>ans;
       if(n==0) return ans;
       sort(arr.begin(),arr.end());
       vector<int> &last=arr[0];
       for(int i=1;i<n;i++){
           if(arr[i][0]<=last[1]){
               last[0]=min(last[0],arr[i][0]);
               last[1]=max(last[1],arr[i][1]);
           }
           else {
               ans.push_back(last);
               last=arr[i];
           }
       }
       ans.push_back(last);
       return ans;
    }
};
