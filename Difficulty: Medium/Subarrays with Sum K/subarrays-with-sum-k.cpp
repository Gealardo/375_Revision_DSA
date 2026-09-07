class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // prefix sum pattern
        int n=arr.size();  int count=0;
        int sum=0; 
        unordered_map<int,int>mp;
        mp[sum]++;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            int req=sum-k;
            if(mp.find(req)!=mp.end()){
                count+=mp[req];
            }
            mp[sum]++;
        }
        return count;
    }
};