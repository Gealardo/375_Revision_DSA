/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1
 * Platform     : GFG
 * Difficulty   : Hard
 */

#include <bits/stdc++.h>
using namespace std;

/* Structure for tree and linked list
class Node {
  public:
    int data;
    Node *left, *right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};*/
class Solution {
  public:
   void in(Node*root , vector<Node*>&arr){
       if(root==NULL) return ;
       in(root->left,arr);
       arr.push_back(root);
       in(root->right,arr);
   }
    Node* treeToDLL(Node* root) {
        vector<Node*>arr;
        in(root,arr);
        int n=arr.size();
        
        for(int i=0;i<n;i++){
          if(i>0) arr[i]->left = arr[i-1];
          if(i+1 < n) arr[i]->right = arr[i+1];
        }
        arr[0]->left = nullptr;
        arr[n-1]->right = nullptr;
        return arr[0];
    }
};
