class Solution {
  public:
    string removeDuplicates(string& s) {
        int n=s.length();
        int i=0;
        string ans="";
        while(i<n){
            if(i+1<n && s[i]==s[i+1]) i++;
            else {
                ans+=s[i];
                i++;
            }
        }
        return ans;
    }
};