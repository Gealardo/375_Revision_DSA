/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/minimum-spanning-tree-kruskals-algorithm/1
 * Platform     : GFG
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class DSU{
    vector<int>parent,rank;
    public:
        DSU(int n){
          parent.resize(n,0);
          rank.resize(n,0);
          for(int i=0;i<n;i++){
             parent[i] = i;
          }
        }
     
       int findParent(int x){
         if(x == parent[x]) return x;
         return parent[x] = findParent(parent[x]);
       }
     
       void union_(int x,int y){
            int px = findParent(x);
            int py = findParent(y);
            if(px == py) return;
            
            if(rank[px] > rank[py]){
                parent[py] = px;
            }else if(rank[px] < rank[py]){
                parent[px] = py;
            }else{
                parent[py] = px;
                rank[px]++;
            }
            return;
       }
    
};
class Solution {
    
  public:

    int kruskalsMST(int V, vector<vector<int>> &edges) {
        
        vector<pair<int,pair<int,int>>>adj(V);
        int E = edges.size();
        for(int i=0;i<E;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj.push_back({wt, {u, v}});
        }
        
        // step 1 : sort all the edges on the basis of their wt;
        sort(adj.begin(),adj.end());
        int mst_cost = 0;
        // step 2 : include edges (execpt which causing cycle)
        DSU d1(V);
        for(auto &it : adj){
            int wt = it.first;
            int u  = it.second.first;
            int v  = it.second.second;
            if(d1.findParent(u) != d1.findParent(v)){
                mst_cost += wt;
                d1.union_(u,v);
            }
        }
        return mst_cost;
    }
};
