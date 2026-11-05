/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/topological-sort/1
 * Platform     : GFG
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void dfs(int node,vector<bool>&visited,vector<vector<int>>& adj,stack<int>&st){
        visited[node] = true;
        for(auto &nighbor:adj[node]){
            if(!visited[nighbor]){
                dfs(nighbor,visited,adj,st);
            }
        }
        st.push(node);
    }
    vector<int> topoSort(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<bool>visited(n,false);
        stack<int>st;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,visited,adj,st);
            }
        }
        vector<int>topo;
        while(!st.empty()){
            topo.push_back(st.top());
            st.pop();
        }
    
        return topo;
    }
};
