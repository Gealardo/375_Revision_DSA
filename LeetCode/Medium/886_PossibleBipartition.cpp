/**
 * Problem Link : https://leetcode.com/problems/possible-bipartition/
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int node,int col, vector<int>&color,vector<vector<int>>& adj){
        color[node] = col;
        for(auto &nighbor : adj[node]){
            if(color[nighbor] == -1){
                color[nighbor] = 1-col;
               if( dfs(nighbor,1-col,color,adj) == false) return false;
            }else{
                if(color[nighbor] == color[node]){
                    return false;
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
       int e = dislikes.size();
       vector<vector<int>>adj(n+1);
       for(int i=0;i<e;i++){
         int u = dislikes[i][0];
         int v = dislikes[i][1];
         adj[u].push_back(v);
         adj[v].push_back(u);
       }
       vector<int>color(n+1,-1);
       for(int i=0;i<n;i++){
         if(color[i] == -1){
            if(dfs(i,0,color,adj)==false) return false;
         }
       }
       return true;
    }
};
