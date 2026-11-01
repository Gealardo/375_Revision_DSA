/**
 * Problem Link : https://leetcode.com/problems/edit-distance/
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int find(int i,int j,string &start,string &target,vector<vector<int>>&dp){
        if(i == 0) return j; // start is empty so need to insert remaining target;
        if(j == 0) return i; // target is empty , delete all start now;

        if(dp[i][j] != -1) return dp[i][j];

        if(start[i-1] == target[j-1]){
            return dp[i][j] = 0 + find(i-1,j-1,start,target,dp);
        }else{
            // insert j-> j-1; delete i-> i-1;  replace i,j-> i-1 j-1;
           int  insert  = find(i,j-1,start,target,dp);
           int  del     = find(i-1,j,start,target,dp);
           int  replace = find(i-1,j-1,start,target,dp);
            return dp[i][j] = 1+min({insert,del,replace});  
        }
    }
    int editDistance(string start, string target) {
      int n = start.length();
      int m = target.size();
      vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
      return find(n,m,start,target,dp);
    }
    int minDistance(string word1, string word2) {
        return editDistance(word1,word2);
    }
};
