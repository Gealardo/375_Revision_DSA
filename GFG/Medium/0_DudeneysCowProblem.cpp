/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/cows-of-fooland5818/1
 * Platform     : GFG
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int total(int n){
        int prev2 = 2;
        int prev = 3;
        for(int i=4;i<=n;i++){
            int curr = prev2 + prev;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    int totalAnimal(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        return total(n);
    }
};
