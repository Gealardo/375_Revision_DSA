/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/maximize-number-of-1s0905/1
 * Platform     : GFG
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
   
        int longestOnes(vector<int>& arr, int k) {
           int n=arr.size();
           int i = 0;
           int j = 0;
           int countz = 0;
           int max_len = 0;
           while(j<n){
              if(arr[j] == 0) countz++;
              if(countz > k){
                if(arr[i]==0) countz--;
                i++;
              }
              max_len = max(max_len,j-i+1);
              j++;
           }
           return max_len;
        }
  
    int maxOnes(vector<int>& arr, int k) {
       return longestOnes(arr,k);
        
    }
};

