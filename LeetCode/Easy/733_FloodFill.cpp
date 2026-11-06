/**
 * Problem Link : https://leetcode.com/problems/flood-fill/
 * Platform     : LeetCode
 * Difficulty   : Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int original_color = image[sr][sc];
        if (original_color == color) {
            return image;
        }
        queue<pair<int,int>>q;
        vector<int>dr = {-1,1,0,0};
        vector<int>dc = {0,0,1,-1};
        
        image[sr][sc] = color;
        q.push({sr,sc});
        while(!q.empty()){
           int i = q.front().first;
           int j = q.front().second;
           q.pop();
           
           for(int k = 0;k < 4;k++){
             int ni = i+dr[k];
             int nj = j+dc[k];
             if(ni>=0 && nj>=0 && ni<n && nj<m && image[ni][nj] == original_color){
                image[ni][nj] = color;
                q.push({ni,nj});
             }
           }
        }
        return image;
    }
};
