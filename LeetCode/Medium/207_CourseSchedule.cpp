/**
 * Problem Link : https://leetcode.com/problems/course-schedule/
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node,vector<bool>&visited,vector<vector<int>>&adj,stack<int>&st){
        visited[node] = true;
         for(auto &nighbor:adj[node]){
            if(!visited[nighbor]){
                dfs(nighbor,visited,adj,st);
            }
         }
        st.push(node);
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<vector<int>>adj(numCourses);
        for(int i=0;i<n;i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
        }
        stack<int>st;
        vector<bool>visited(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                dfs(i,visited,adj,st);
            }
        }
        vector<int>pos(numCourses,0);int i=0;
        while(!st.empty()){
            pos[st.top()] = i;
            i++;
            st.pop();
        }
        for(int u=0;u<numCourses;u++){
            for(auto &v : adj[u]){
                if(pos[u] >= pos[v]) return false;
            }
        }
        return true;
    }
};
