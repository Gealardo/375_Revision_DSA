/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/merge-two-bst-s/1
 * Platform     : GFG
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
}; */

class Solution {
  public:
    void in(Node*r,vector<int>&ans){
        if(r==nullptr) return;
        in(r->left , ans);
        ans.push_back(r->data);
        in(r->right , ans);
    }
    vector<int> merge(Node *r1, Node *r2) {
      vector<int>ans;
      in(r1,ans); in(r2,ans);
      sort(ans.begin(),ans.end());
      return ans;
    }
};
