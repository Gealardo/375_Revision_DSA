/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/bst-to-greater-sum-tree/1
 * Platform     : GFG
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};*/

class Solution {
  public:
    void find(Node* root,int &prev_sum){
        if(root==nullptr) return ;
        find(root->right,prev_sum);
        
        int curr_val = root->data;
        root->data = prev_sum;
        prev_sum+=curr_val;
        
        find(root->left,prev_sum);
        return;
    }
    void transformTree(Node *root) {
        
        int prev_sum = 0;
        find(root,prev_sum);
        
    }
};
