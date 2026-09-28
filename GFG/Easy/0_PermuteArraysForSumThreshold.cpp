/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/permutations-in-array1747/1
 * Platform     : GFG
 * Difficulty   : Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isPossible(int k, vector<int> &a, vector<int> &b) {
        // O(nlogn + mlogm + max(m,n)) = xlongx;
        int n=a.size();
        int m=b.size();
        sort(a.begin(),a.end());
        sort(b.rbegin(),b.rend());
        int s = (n>m)? n:m ;
        for(int i=0;i<s;i++){
            if(i<m && i<n){
              if(a[i]+b[i] < k) return false;
            }
            else {
                if(i<n){
                    if(a[i]<k) return false;
                }
                else if(b[i]<k) return false;
            }
        }
      return true;  
    }
};
