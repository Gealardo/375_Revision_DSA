/**
 * Problem Link : https://leetcode.com/problems/keys-and-rooms/
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node,vector<vector<int>>& rooms,vector<bool>&visited,int &count){
        visited[node] = true;
        count++;
        for(auto &nighbor:rooms[node]){
            if(!visited[nighbor]){
                dfs(nighbor,rooms,visited,count);
            }
        }
        return;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
       int n = rooms.size(); 
       vector<bool>visited(n,false);
       int count = 0;
       dfs(0,rooms,visited,count); 
       return count == n;
    }
};
