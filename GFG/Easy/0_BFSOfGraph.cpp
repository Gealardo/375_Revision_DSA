/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
 * Platform     : GFG
 * Difficulty   : Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        int n = adj.size();
        vector<int>ans;
        vector<bool>visited(n,false);
        
        queue<int>q;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                q.push(i);visited[i] = true;
                while(!q.empty()){
                   int node = q.front();
                   q.pop();
                   
                   ans.push_back(node);
                   for(auto &nighbor : adj[node]){
                       if(!visited[nighbor]){
                           q.push(nighbor);
                           visited[nighbor] = true;
                       }
                   }
            }
                
                
            }
            
        }
        return ans;
        
    }
};
