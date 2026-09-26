/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/maximum-repeating-number4858/1
 * Platform     : GFG
 * Difficulty   : Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxRepeating(int k, vector<int>& arr) {
        unordered_map<int,int>mp;
        int max_f=0;
        int ans=0;
        for(auto &x:arr){
            mp[x]++; 
            // less that
            if(max_f < mp[x]){
                max_f = mp[x];
                ans = x;
            }
            else if(max_f == mp[x]){
                if(ans > x) ans = x;
            }
        }
       return ans;
    }
};
