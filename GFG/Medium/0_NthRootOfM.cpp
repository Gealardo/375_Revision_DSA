/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/find-nth-root-of-m5843/1
 * Platform     : GFG
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int nthRoot(int N, int M) {
       int l = 1;
       int h = M;
       if(M == 0) return 0;
       while(l<=h){
          int x = l+(h-l)/2;
          long long x_nt = 1;
          bool exeeded = false;
          for(int i=0;i<N;i++){
              if(M / x < x_nt){
                exeeded = true;
                break;
              }
               x_nt *= x;
          }
          if(x_nt == M && !exeeded) return x;
          else if(exeeded || x_nt > M) h = x-1;
          else{
             l = x+1;
          }    
       }
       return -1;
    }
};

