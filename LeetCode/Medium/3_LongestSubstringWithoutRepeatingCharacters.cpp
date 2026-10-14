/**
 * Problem Link : https://leetcode.com/problems/longest-substring-without-repeating-characters/
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       unordered_map<char,int>mp;
       int l=0;
       int h=0;
       int maxl=0;
       int n= s.length();
       while(h<n){

         mp[s[h]]++;
         
         while(mp[s[h]]>1){
            mp[s[l]]--;
            l++;
         }

         maxl = max(maxl,h-l+1);
         h++;
       }
       return maxl; 
    }
};
