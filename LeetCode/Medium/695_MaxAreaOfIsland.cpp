/**
 * Problem Link : https://leetcode.com/problems/max-area-of-island/
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int i,int j,int n, int m,int &area,vector<vector<int>>& grid){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j] == 0) return;
        grid[i][j] = 0;
        area += 1;
        dfs(i-1,j,n,m,area,grid);
        dfs(i,j-1,n,m,area,grid);
        dfs(i+1,j,n,m,area,grid);
        dfs(i,j+1,n,m,area,grid);
        return;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int max_area = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    int area = 0;
                    dfs(i,j,n,m,area,grid);
                    max_area = max(max_area,area);
                }
            }
        }
        return max_area;
    }
};
