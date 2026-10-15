/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/maximum-triplet-product--170647/1
 * Platform     : GFG
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxTripletProduct(vector<int>& arr) {
       priority_queue<int,vector<int>,greater<int>>minh;
       priority_queue<int>maxh;
       for(auto &x:arr){
           minh.push(x);
           maxh.push(x);
           if(minh.size()>3) minh.pop();
           if(maxh.size()>2) maxh.pop();
       }
       int a = 1;
       int max_e=minh.top();
       while(!minh.empty()){
           a=a*minh.top();
           max_e = max(max_e,minh.top());
           minh.pop();
       }
       int min_e1 = maxh.top();
       maxh.pop();
       int min_e2 = maxh.top();
       int b = min_e1 * min_e2 * max_e;
       return max(a,b);
        
    }
};
