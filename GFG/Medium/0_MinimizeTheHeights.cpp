/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1
 * Platform     : GFG
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int mini = arr[0]+k;
        int maxi = arr[n-1]-k;
        int ans = arr[n-1]-arr[0];
        for(int i=0;i<n-1;i++){
            // slit at i 
           int m1=max(maxi,arr[i]+k);
           int m2=min(mini,arr[i+1]-k);
           if(m2<0) continue;
           ans = min(ans,m1-m2);
        }
        return ans;
    }
};
