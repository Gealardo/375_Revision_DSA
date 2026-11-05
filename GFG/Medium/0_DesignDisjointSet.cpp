/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/disjoint-set-union-find/1
 * Platform     : GFG
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class MyDSU {
    // parent , rank declaration
    vector<int>parent;
    vector<int>rank;
  public:
    MyDSU(int n) {
        // setup of parent and rank
        parent.resize(n+1,0);
        rank.resize(n+1,0);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }
    // find ultimate parent of x
    int find(int x) {
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);// path comperation
    }

    // unioun of x and y    
    void unionSet(int x, int y) {
        /*
        1) find the parent of x and y as px and py respectivily;
        2) if they are equal , they already in union;
        3) compare the ranks of their parents; 
        4) lesser ranked parent will changed (new parent will be larger one);
        5) if equal then make one parent of other and hence the rank will increase by one whick become parent.
        */
        int px = find(x);
        int py = find(y);
        if(px == py) return;
        
        // if(rank[px] > rank[py]){
        //     parent[py] = px;
        // }else if(rank[px] < rank[py]){
        //     parent[px] = py;
        // }else{
        //     parent[px] = py;
        //     rank[py]++;
        // }
        parent[px] = py;
    }
};
