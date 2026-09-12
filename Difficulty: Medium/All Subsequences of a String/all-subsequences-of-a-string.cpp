class Solution {
  public:
    void solve(int i,string sub,vector<string>&ans,string &s){
        if(i<0){
            reverse(sub.begin(),sub.end());
            ans.push_back(sub);
            return;
        }
        solve(i-1,sub+s[i],ans,s);
        solve(i-1,sub,ans,s);
    }
    vector<string> powerSet(string &s) {
      int n=s.length();
      vector<string>ans;
      string sub="";
      solve(n-1,sub,ans,s);
      sort(ans.begin(),ans.end());
      return ans;
    }
};