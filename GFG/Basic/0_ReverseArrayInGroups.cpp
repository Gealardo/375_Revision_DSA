/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/reverse-array-in-groups0255/1
 * Platform     : GFG
 * Difficulty   : Basic
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void reverseInGroups(vector<int> &arr, int k) {
       int n=arr.size();
       int i=0;
       while(i<n){
          int h =  min(k+i-1 , n-1);
          for(int j=i ; j<=(h+i)/2 ; j++){
              swap(arr[j] , arr[h - (j - i)]);
          }
          i=h+1;
       }
    }
};

