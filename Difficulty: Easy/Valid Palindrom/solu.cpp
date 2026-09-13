class Solution {
public:
    bool isPalindrome(string s) {
        string news="";
        for(auto &c:s){
            if((c>='a' && c<='z') || (c>='A' && c<='Z')) c = tolower(c);
            if(c>='a' && c<='z') news+=c;
            else if(c>='0' && c<='9') news+=c;
        }
        int l=0;
        int r=news.length()-1;
        while(l<r){
            if(news[l]!=news[r]) return false;
            l++; r--;
        }
        return true;
    }
};
