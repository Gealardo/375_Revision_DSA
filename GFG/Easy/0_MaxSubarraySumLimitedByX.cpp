/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/maximum-sum-of-subarray-less-than-or-equal-to-x4033/1
 * Platform     : GFG
 * Difficulty   : Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxSum(vector<int>& arr, int x) {
        int n=arr.size();
        int l=0;
        int h=0;
        int sum =0;
        int maxi=0;
        while(h<n){
            sum+=arr[h];
            while(sum>x && l<=h){
                sum-=arr[l];
                l++;
            }
            
            maxi=max(sum,maxi);
            h++;
        }
        return maxi;
    }
};
