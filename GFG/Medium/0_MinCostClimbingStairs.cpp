/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/min-cost-climbing-stairs/1
 * Platform     : GFG
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

//Back-end complete function Template for C++

class Solution {
  public:
    int find(int i,int n,vector<int>&dp,vector<int>&cost){
        if( i< 0) return 0;
        if(i==0) return dp[0]=cost[0];
        if(i==1) return dp[1]=cost[1];
        if(dp[i]!=-1) return dp[i];
        int oneStep = cost[i] + find(i-1,n,dp,cost);
        int twoStep = cost[i] + find(i-2, n, dp, cost);
        
        return dp[i] = min(oneStep,twoStep);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n,-1);
        return min(find(n-1, n, dp, cost), find(n-2, n, dp, cost));;
    }
};
