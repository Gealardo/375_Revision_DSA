/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/sum-of-subarrays2229/1
 * Platform     : GFG
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int subarraySum(vector<int>& arr) {
       int n=arr.size();
       int s=0;
       for(int i=0;i<n;i++){
           s+=arr[i]*(i+1)*(n-i);
       }
       return s;
    }
};
/*
  value*frequency
  arr[i]*(left_*right_)
  left=i+1;
  right=n-1;
*/
