/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/move-all-zeroes-to-end-of-array0751/1
 * Platform     : GFG
 * Difficulty   : Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        int n = arr.size();
        for(int i=0,j=0;j<n;j++){
            if(arr[j]!=0){
                swap(arr[j],arr[i]);
                i++;
            }
        }
    }
};
