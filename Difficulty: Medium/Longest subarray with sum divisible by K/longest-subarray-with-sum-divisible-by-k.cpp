class Solution {
  public:
    int longestSubarrayDivK(vector<int>& arr, int k) {
        //prefix sum
        int n=arr.size();
        int len=0; int maxlen=0;
        long long sum=0; unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            
            int rem = sum%k;
            if(rem<0) rem+=k;
            
            if(rem==0){
               maxlen=max(maxlen,i+1); 
            }
            else if(mp.find(rem)!=mp.end()){
               len=i-mp[rem];
               maxlen=max(maxlen,len);
            }
            else{
                mp[rem]=i;
            }
        }
        return maxlen;
    }
};