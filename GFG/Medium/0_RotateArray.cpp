/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/rotate-array-by-n-elements-1587115621/1
 * Platform     : GFG
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void rotateArr(vector<int>& arr, int d) {
        int n = arr.size();
        reverse(arr.begin(),arr.begin()+d%n);
        reverse(arr.begin()+d%n,arr.end());
        reverse(arr.begin(),arr.end());
        
    }
};
