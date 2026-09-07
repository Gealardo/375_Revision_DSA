class Solution {
public:
    void solve(int i,vector<vector<int>>&ans,vector<int>&subans,int k){
        if(subans.size()>k) return;
        if(i<1){
            if(subans.size()==k)ans.push_back(subans);
            return;
        }
        subans.push_back(i);
        solve(i-1,ans,subans,k);
        subans.pop_back();
        solve(i-1,ans,subans,k);
    }
    vector<vector<int>> combine(int n, int k) {
       // vector<int>arr;
       // for(int i=1;i<=n;i++) arr.push_back(i);
        vector<vector<int>>ans;
        vector<int>subans;
        solve(n,ans,subans,k);
        return ans;
    }
};
