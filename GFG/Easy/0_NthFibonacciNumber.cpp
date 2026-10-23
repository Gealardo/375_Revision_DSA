/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/nth-fibonacci-number1335/1
 * Platform     : GFG
 * Difficulty   : Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int febo(int n){
        int prev2 = 0;
        int prev = 1;
        for(int i=1;i<n;i++){
            int curr = prev2 + prev;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    int nthFibonacci(int n) {
      if(n==0) return 0; 
      return febo(n);  
    }
};
