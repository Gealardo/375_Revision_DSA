/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1
 * Platform     : GFG
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int primMST(vector<vector<vector<int>>> &adj) {
       int V = adj.size();
      
       vector<bool>visited(V,false);
       vector<pair<int,int>>mst;
       int mst_cost = 0;
       typedef pair<int,pair<int,int>>p;
       priority_queue< p,vector<p>,greater<p>>q;
       q.push({0,{0,-1}});
       
       while(!q.empty()){
           auto topElement = q.top();
           q.pop();
           
           int wt = topElement.first;
           int u = topElement.second.first;
           int parent = topElement.second.second;
           
           if(visited[u]) continue;
           
           visited[u] = true;
           mst_cost += wt;
           mst.push_back({parent,0});
           
           for(auto &it:adj[u]){
               int wt = it[1];
               int ni = it[0];
               
               if(!visited[ni]){
                   q.push({wt,{ni,u}});
               }
           }
       }
       return mst_cost;
    }
};
