/**
 * Problem Link : https://leetcode.com/problems/is-graph-bipartite/
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // bfs , just color with 2 colours
        int n = graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
           if(color[i]==-1){
              queue<int>q;
              q.push(i);
              color[i]= 0;
              while(!q.empty()){
                 int node = q.front();
                 q.pop();
                 for(auto &nighbor : graph[node]){
                     if(color[nighbor] == -1){
                        color[nighbor] = !color[node];
                        q.push(nighbor);
                     }
                     else{
                        if(color[nighbor] == color[node]){
                            return false;
                        }
                     }
                 }
              }
           }
        }
        return true;
    }
};
