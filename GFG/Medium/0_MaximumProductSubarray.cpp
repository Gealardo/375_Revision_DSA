/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/1
 * Platform     : GFG
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxProduct(vector<int> &arr) {
       int n=arr.size();
       long long pro1 =INT_MIN; 
       long long pro2 = INT_MAX; long long result=INT_MIN;
       for(int i=0;i<n;i++){
           if(arr[i]<0) swap(pro1,pro2);
           pro1 = max((long long)arr[i],arr[i]*pro1);
           pro2 = min((long long)arr[i],arr[i]*pro2);
           result = max(pro1,result);
       }
       return (int)result;
    }
};
