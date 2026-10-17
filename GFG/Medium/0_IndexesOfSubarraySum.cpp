/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1
 * Platform     : GFG
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        int n=arr.size();
        int l=0;
        int h=0;
        int sum=0;
        vector<int>ans;
        while(h<n){
            sum+=arr[h];
            while(sum>target && l<=h){
                sum-=arr[l];
                l++;
            }
            if(sum == target){
                ans.push_back(l+1); ans.push_back(h+1);
                break;
            }
            h++;
        }
        if(ans.size()==0) ans.push_back(-1);
        return ans;
    }
};
