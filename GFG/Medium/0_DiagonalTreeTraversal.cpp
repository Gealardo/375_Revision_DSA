/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1
 * Platform     : GFG
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

/* Structure of binary tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    vector<int> diagonal(Node *root) {
        vector<int>ans;
        if(root==nullptr) return ans;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            Node* node = q.front();
            q.pop();
            while(node!=nullptr){
                ans.push_back(node->data);
                if(node->left!=nullptr) q.push(node->left);
                node = node->right;
            }
        }
      return ans;  
    }
};
