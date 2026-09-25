/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/is-it-a-tree/1
 * Platform     : GFG
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool dfs(int parent,int node,vector<vector<int>>&adj,vector<bool>&visited){
        visited[node]=true;
        for(auto &nighbor : adj[node]){
            if(!visited[nighbor]){
              if( dfs(node,nighbor,adj,visited)==false) return false;
            }
            else{
                if(parent != nighbor){
                    return false;
                }
            }
        }
        return true;
    }
    bool isTree(int n, int m, vector<vector<int>> &edges) {
        vector<vector<int>>adj(n);
        for(auto &it:edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int x=0;
        vector<bool>visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                x++;
               if(dfs(-1,i,adj,visited)==false) return false;
            }
        }
        return (x==1)? true:false;
    }
};

