class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
       vector<int>temp=arr;
       vector<int>ans;
       int n=arr.size();
       for(int i=0;i<n;i++){
           if( temp[arr[i]-1]<0) ans.push_back(arr[i]); 
           else temp[arr[i]-1]=- temp[arr[i]-1];
       }
       for(int i=0;i<n;i++){
           if(temp[i]>0) ans.push_back(i+1);
       }
       return ans;    
    }
};