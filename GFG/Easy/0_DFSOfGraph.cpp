/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
 * Platform     : GFG
 * Difficulty   : Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void dfs(int node,vector<vector<int>>& adj,vector<int>&ans,vector<bool>&visited){
        visited[node] = true;
        ans.push_back(node);
        for(auto &nighbor : adj[node]){
            if(!visited[nighbor]){
                dfs(nighbor,adj,ans,visited);
            }
        }
        return;
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int>ans;
        vector<bool>visited(n,false);
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,adj,ans,visited);
            }
        }
        return ans;
    }
};
