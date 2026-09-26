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
      vector<int>ans1; vector<int>ans2;
      in(r1,ans1); in(r2,ans2);
      int n=ans1.size() ; int m=ans2.size();
      vector<int>ans(n+m);
      int k=0;
      int i=0; int j=0;
      while(i<n && j<m){
          if(ans1[i] < ans2[j]) ans[k++]=ans1[i++];
          else ans[k++] = ans2[j++]; 
      }
      while(i<n) ans[k++] = ans1[i++];
      while(j<m) ans[k++] = ans2[j++];
      return ans;
    }
};
