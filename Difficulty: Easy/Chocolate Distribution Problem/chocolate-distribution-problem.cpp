class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
       sort(a.begin(),a.end());
       int n=a.size();
       int l=0;
       int r=m-1;
       int diff=0;
       int mindiff=a[m-1]-a[0];
       while(r<n){
           diff=a[r]-a[l];
           mindiff=min(mindiff,diff);
           r++;l++;
       }
       return mindiff;
    }
};