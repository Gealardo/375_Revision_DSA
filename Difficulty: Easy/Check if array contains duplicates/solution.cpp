class Solution {
  public:
    bool checkDuplicates(vector<int> &arr) {
      unordered_map<int,int>mp;
      int n=arr.size();
      for(int i=0;i<n;i++){
          if(mp.find(arr[i])!=mp.end()) return true;
          mp[arr[i]]=i;
      }
       return false; 
    }
};
