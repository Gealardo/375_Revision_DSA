/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/counting-sort/1
 * Platform     : GFG
 * Difficulty   : Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string countSort(string s) {
        // 97 -122
      vector<int>arr(26,0);
      int l = s.size();
      for(int i=0;i<l;i++){
        arr[s[i]-'a']++;  
      }
      string ss="";
      for(int i=0;i<26;i++){
        int f = arr[i];
        for(int j=0;j<f;j++){
            ss += char(i+'a');
        }
      }
      return ss;
    }
};
