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
       map<char,int>mp;
       string ss = "";
       int size =  s.size();
       for(int i=0;i<size;i++){
           mp[s[i]]++;
       }
       for(auto &it:mp){
          for(int i=0;i<it.second;i++){
              ss+=it.first;
          } 
       }
       return ss;
    }
};
