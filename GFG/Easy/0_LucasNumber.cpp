/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/lucas-number4515/1
 * Platform     : GFG
 * Difficulty   : Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
   long long lu(int n) {
           if (n == 0) return 2;
           if (n == 1) return 1;

           long long prev2 = 2;
           long long prev = 1;
           long long mod = 1000000007;
           for (int i = 2; i <= n; i++) {
               long long curr = (prev2 + prev)%mod;
               prev2 = prev;
               prev = curr;
           }

           return prev;
       }
    long long lucas(int n) {
       if(n==0) return 2;
       return lu(n);
    }
};

