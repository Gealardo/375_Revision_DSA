/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/max-consecutive-one/1
 * Platform     : GFG
 * Difficulty   : Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxConsecBits(vector<int> &arr) {
        // cons 1's 
        int max_one = 0;
        int maxi_one=0;
        int n= arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]==1){
                maxi_one++;
            }
            else{
                maxi_one = 0;
            }
            max_one= max(max_one,maxi_one);
        }
        // cons 0's
        int max_z = 0;
        int maxi_z=0;
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                maxi_z++;
            }
            else{
                maxi_z = 0;
            }
            max_z= max(max_z,maxi_z);
        }
     return max(max_one,max_z);    
    }
};
