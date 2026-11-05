/**
 * Problem Link : https://leetcode.com/problems/course-schedule-ii/
 * Platform     : LeetCode
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
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
          int n = numCourses;
          int e = prerequisites.size();
          vector<vector<int>>adj(n);
          for(int i=0;i<e;i++){
              int u = prerequisites[i][0];
              int v = prerequisites[i][1];
              adj[v].push_back(u);
          }
        vector<bool>visited(n,false);
        stack<int>st;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,visited,adj,st);
            }
        }
        vector<int>pos(n,0); int i=0;
        stack<int>temp = st;
        while(!temp.empty()){
            pos[temp.top()] = i;
            i++; temp.pop();
        }
        vector<int>topo;
        for(int u=0;u<n;u++){
            for(auto &v : adj[u]){
                if(pos[u] >= pos[v]) return {};
            }
        }
        while(!st.empty()){
            topo.push_back(st.top());
            st.pop();
        }
    
        return topo;
    }
};
