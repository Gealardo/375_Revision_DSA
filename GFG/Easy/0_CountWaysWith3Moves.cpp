/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/count-number-of-hops-1587115620/1
 * Platform     : GFG
 * Difficulty   : Easy
 */

#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int countWays(int n) {
       int prev3 = 1;
       int prev2 = 2;
       int prev = 4;
       if(n<3) return n;
       if(n==3) return prev;
       for(int i=4;i<=n;i++){
           int curr = prev3+prev2+prev;
           prev3 = prev2;
           prev2 = prev;
           prev = curr;
       }
       return prev;
    }
};

