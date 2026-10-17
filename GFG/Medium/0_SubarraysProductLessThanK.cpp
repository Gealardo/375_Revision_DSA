/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/count-the-subarrays-having-product-less-than-k1708/1
 * Platform     : GFG
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countSubarray(vector<int>& arr, int k) {
        int count=0;
        int n=arr.size();
        int l=0;
        int h=0;
        long long pro =1;
        while(h<n){
            pro*=arr[h];
          
            while(pro>=k && l<=h){
                pro/=arr[l];
                l++;
            }
            count += h-l+1;
            h++;
        }
        return count;
    }
};
