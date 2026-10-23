/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/tribonacci-number/1
 * Platform     : GFG
 * Difficulty   : Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int tribo(int n){
        int prev3 = 0;
        int prev2 = 1;
        int prev  = 1;
        if(n<2) return n;
        if(n==2) return n-1;
        for(int i=3;i<=n;i++){
            int curr = prev3+prev2+prev;
            prev3 = prev2;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    int nthTribonacci(int n) {
       return tribo(n);
    }
};

