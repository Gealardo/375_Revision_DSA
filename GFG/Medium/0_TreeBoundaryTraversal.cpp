/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
 * Platform     : GFG
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

/* Node Structure
class Node {
  public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    void right_side(Node* root,vector<int>&b){
        if(root==nullptr) return;
        vector<int>r;
        Node* curr = root->right;
        while(curr!=nullptr){
            if(curr->left!=nullptr || curr->right!=nullptr){
                r.push_back(curr->data);
            }
            if(curr->right!=nullptr){
               curr=curr->right;
            }else{
               curr = curr->left;
            }
        }
        reverse(r.begin(),r.end());
        for(auto &x:r) b.push_back(x);
    }
    void bottom(Node*root,vector<int>&b){
        if(root==nullptr) return;
        bottom(root->left,b);
        if(root->left==nullptr && root->right==nullptr){
            b.push_back(root->data);
        }
        bottom(root->right,b);
    }
    void left_side(Node* root,vector<int>&b){
     if(root==nullptr) return;    
      Node* curr = root->left;
      while (curr!=nullptr){
         if(curr->left!=nullptr || curr->right!=nullptr){
           b.push_back(curr->data);
         }
          if(curr->left!=nullptr){
             curr=curr->left;
         }else{
             curr=curr->right;
         }
      }
     
    }
    vector<int> boundaryTraversal(Node *root) {
        vector<int>b;
        if(root==nullptr) return b;
        b.push_back(root->data);
        left_side(root,b);
        if(root->left!=nullptr || root->right!=nullptr)  bottom(root,b);
       
        right_side(root,b);
        return b;
    }
};
