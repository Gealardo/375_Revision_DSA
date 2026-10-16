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
        int h=0;
        while(h<n){
            maxi+=arr[h];
            ans = max(ans,maxi);
            if(maxi<0) maxi=0;
            h++;
        }
        return ans;
    }
};
