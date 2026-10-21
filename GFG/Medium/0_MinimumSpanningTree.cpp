/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1
 * Platform     : GFG
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
       //by using prim's algo
       int E = edges.size();
       vector<vector<pair<int,int>>>adj(V);
       for(int i=0;i<E;i++){
           int u = edges[i][0];
           int v =  edges[i][1];
           int wt = edges[i][2];
           adj[u].push_back({v,wt});
           adj[v].push_back({u,wt});
       }
              vector<bool>inMST(V,false);
              priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
              int Cost=0;
              pq.push({0,0});
              while(!pq.empty()){
               int u = pq.top().second;
               int wt = pq.top().first;
               pq.pop();
               if(!inMST[u]){
                   inMST[u] = true;
                   Cost+=wt;
                   for(auto &it : adj[u]){
                       int v = it.first;
                       int w = it.second;
                       if(!inMST[v]){
                           pq.push({w,v});
                       }
                   } 
               }
              }
              return Cost;
        
    }
};
