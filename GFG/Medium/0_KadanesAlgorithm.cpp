/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1
 * Platform     : GFG
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        int n = arr.size();
        int maxi = 0;
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            maxi = max(arr[i],maxi+arr[i]);
            ans = max(ans,maxi);
        }
        return ans;
    }
};
