/**
 * Problem Link : https://leetcode.com/problems/number-of-islands/
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int>r={-1,1,0,0};
    vector<int>c={0,0,1,-1};
    void dfs(int i,int j ,int row,int col,vector<vector<char>>& grid){
        if(i<0 || j<0 || i>=row || j>=col || grid[i][j] == '0') return;
        grid[i][j] = '0';
        for(int k=0;k<4;k++){
            int ni = i+r[k];
            int nj = j+c[k];
            dfs(ni,nj,row,col,grid);
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int iland = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] != '0'){
                    iland++;
                  dfs(i,j,n,m,grid);
                }
            }
        }
        return iland;
    }
};
