/**
 * Problem Link : https://leetcode.com/problems/course-schedule/
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<vector<int>>adj(numCourses);
        for(int i=0;i<n;i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
        }
        vector<int>indegre(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto &x:adj[i]){
                indegre[x]++;
            }
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegre[i]==0) q.push(i);
        }
        int count = 0; 
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            for(auto &c : adj[node]){
                indegre[c]--;
                if(indegre[c]==0) q.push(c);
            }
        }
        return count == numCourses;
    }
};
