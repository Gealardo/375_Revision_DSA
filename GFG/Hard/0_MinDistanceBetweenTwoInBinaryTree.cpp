/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1
 * Platform     : GFG
 * Difficulty   : Hard
 */

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node
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
    Node* lca(Node*root ,int a, int b ){
        if(root==nullptr) return nullptr;
        if(root->data == a || root->data == b) return root;
        Node* left = lca(root->left,a,b);
        Node* right = lca(root->right,a,b);
        if(left!=NULL && right!=NULL) return root;
        else if(left!=NULL) return left;
        else return right;
    }
    int height(Node*p , int x,int h){
        if(p==NULL) return 0;
        if(p->data == x) return h;
        int left = height(p->left , x, h+1);
        if(left != 0 ) return left;
        int right = height(p->right ,x,h+1);
        return right;
    }
    int findDist(Node* root, int a, int b) {
       Node* p = lca(root,a,b);
       int h1 = height(p,a,1);
       int h2 = height(p,b,1);
       return (h1-1)+(h2-1);
    }
};
