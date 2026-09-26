/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1
 * Platform     : GFG
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        priority_queue<int>pq;
        for(auto &x:arr){
            pq.push(x);
            if(pq.size()>k)pq.pop();
        }
        return pq.top();
    }
};
