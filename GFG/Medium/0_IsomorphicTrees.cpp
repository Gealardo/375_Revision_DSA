/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/check-if-tree-is-isomorphic/1
 * Platform     : GFG
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

/* Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool find(Node*root1,Node*root2){
        if(root1==NULL && root2==NULL) return true;
        if(root1==NULL || root2==NULL) return false;
        if(root1->data != root2->data) return false;
        bool noSwap = find(root1->left, root2->left) && find(root1->right, root2->right);
        bool swap = find(root1->left, root2->right) && find(root1->right, root2->left);
        return noSwap || swap;
        
    } 
    bool isIsomorphic(Node *root1, Node *root2) {
        return find(root1,root2);
    }
};
