/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/next-greater-element/1
 * Platform     : GFG
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> nextGreater(vector<int> &arr) {
       stack<pair<int,int>>st;
       int n=arr.size();
       vector<int>ans(n,-1);
       for(int i=0;i<2*n;i++){
          while(!st.empty() && arr[i%n]>st.top().first){
              ans[st.top().second] = arr[i%n];
              st.pop();
          }
          if(i<n){
             st.push({arr[i%n],i%n});  
          }
       }
       return ans;
    }
};
