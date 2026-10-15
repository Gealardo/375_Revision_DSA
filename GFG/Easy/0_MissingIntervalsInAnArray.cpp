/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/missing-ranges-of-numbers1019/1
 * Platform     : GFG
 * Difficulty   : Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> missingRanges(vector<int> &arr, int lower, int upper) {
        vector<vector<int>>ans;
        int n=arr.size();
        int l=lower;
        for(int i=0;i<n;i++){
            vector<int>sub;
            int mini = l;
            int maxi = arr[i];
            if(maxi-mini>=1){
                sub.push_back(mini);
                sub.push_back(maxi-1);
            }
            l=arr[i]+1;
            if(!sub.empty())ans.push_back(sub);
        }
        if(upper-arr[n-1]>=1) {
            vector<int>sub;
            sub.push_back(arr[n-1]+1);
            sub.push_back(upper);
            ans.push_back(sub);
        }
        return ans;
    }
};

