/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1
 * Platform     : GFG
 * Difficulty   : Easy
 */

#include <bits/stdc++.h>
using namespace std;

/* Structure for Tree Node
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
};
*/

class Solution {
  public:
    int sum(Node*&root){
        if(root==nullptr) return 0;
        int old = root->data;
        int left = sum(root->left);
        int right = sum(root->right);
        root->data = left+right;
        return root->data + old;
    }
    void toSumTree(Node *root) {
        sum(root);
        return;
    }
};
