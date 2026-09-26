/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/attend-all-meetings/1
 * Platform     : GFG
 * Difficulty   : Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
       int n = arr.size();
       sort(arr.begin(),arr.end());
       vector<int>last = arr[0];
       for(int i=1;i<n;i++){
            if(last[1]>arr[i][0]) return false;
            last = arr[i];
       }
      
       return true;    
    }
};
