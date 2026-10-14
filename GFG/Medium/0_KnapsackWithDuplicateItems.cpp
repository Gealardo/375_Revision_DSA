/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1
 * Platform     : GFG
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int fun(int i, int n,vector<int>& val, vector<int>& wt, int capacity,int new_cap,vector<vector<int>>&dp){
        if(i>=n || new_cap <= 0 ) return 0;
        if(dp[i][new_cap]!=-1) return dp[i][new_cap];
        int nottake = 0+fun(i+1,n,val,wt,capacity,new_cap,dp);
        int take=0;
        if(wt[i] <= new_cap) take = val[i] + fun(i,n,val,wt,capacity,new_cap-wt[i],dp);
        return dp[i][new_cap]= max(take,nottake);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n =val.size();
        vector<vector<int>>dp(n,vector<int>(capacity+1,-1));
        return fun(0,n,val,wt,capacity,capacity,dp);
    }
};
