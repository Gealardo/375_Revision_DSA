/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/k-largest-elements4206/1
 * Platform     : GFG
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
       priority_queue<int , vector<int> , greater<int>>minh;
       for(auto &x:arr){
           minh.push(x);
           if(minh.size()>k) minh.pop();
       }
        vector<int>ans(k,0);
        int i=k-1;
        while(!minh.empty()){
            ans[i]=minh.top();
            minh.pop(); i--;
        }
        return ans;
    }
};
