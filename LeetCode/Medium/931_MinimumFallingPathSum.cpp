/**
 * Problem Link : https://leetcode.com/problems/minimum-falling-path-sum/
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int find(int i,int j,int n,vector<vector<int>>& matrix){
        // base case
        if(j<0 || j>=n) return 1e9;
        if(i==n-1) return matrix[i][j];

        int down = find(i+1,j,n,matrix);
        int left_down = find(i+1,j-1,n,matrix);
        int right_down = find(i+1,j+1,n,matrix);
        
        return matrix[i][j] + min({down,left_down,right_down});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // greedy fails -> tryout all possibilities
        int n = matrix.size();

        int min_total_path = 1e9;
         for(int j = 0; j < n; j++) {
            min_total_path = min(min_total_path, find(0, j, n, matrix));
        }
        
        return min_total_path;
    }
};
