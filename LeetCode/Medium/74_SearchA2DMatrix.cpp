/**
 * Problem Link : https://leetcode.com/problems/search-a-2d-matrix/
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int n = matrix.size();
       int m = matrix[0].size();
       if(n==0 || m==0) return false;
       int low = 0;
       int high = (n*m)-1;
       while(low<=high){
          int m1D = low+(high-low)/2;
          pair<int,int>mid = {(m1D/m),(m1D%m)};

          if(target == matrix[mid.first][mid.second]) return true;
          else if(target < matrix[mid.first][mid.second]) high = m1D-1;
          else low = m1D+1;
       }
       return false; 
    }
};
