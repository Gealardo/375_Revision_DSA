/**
 * Problem Link : https://leetcode.com/problems/longest-repeating-character-replacement/
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        // len - mfreq = k
        unordered_map<char,int>mp;
        int mfreq=0;
        int l=0;
        int h=0;
        int maxl=0;
        int n=s.length();
        while(h<n){
          mp[s[h]]++;
          mfreq = max(mfreq , mp[s[h]]);
          while((h-l+1) - mfreq >k){
               mp[s[l]]--;
               l++;
          }
          maxl=max(maxl,h-l+1);
          h++;
        }
        return maxl;
    }
};
