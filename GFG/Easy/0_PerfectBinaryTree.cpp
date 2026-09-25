/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/perfect-binary-tree/1
 * Platform     : GFG
 * Difficulty   : Easy
 */

#include <bits/stdc++.h>
using namespace std;

/*Node structure
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
   int h(Node*root){
         if(root==nullptr) return 0;
         int left = h(root->left);
         int right = h(root->right);
         if(left==-1 || right==-1 || abs(left-right)!=0) return -1;
         return 1 + max(left,right);
       }
       bool check(Node* root) {
           if(root==nullptr) return true;
           return (h(root)==-1)? false:true;
       }
    bool isPerfect(Node *root) {
      return check(root);
        
    }
};
