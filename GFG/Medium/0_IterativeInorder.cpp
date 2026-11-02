/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/inorder-traversal-iterative/1
 * Platform     : GFG
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

/*
Definition for Node
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
    vector<int> inOrder(Node* root) {
       // left root right
       vector<int>inorder;
       Node* temp = root;
       stack<Node*>s;
       while(temp!=nullptr || !s.empty()){
           
           // find the smallest
           while(temp!=nullptr){
               s.push(temp);
               temp = temp->left;
           }
           // now temp is null , stack top is smallest
           temp = s.top();
           s.pop();
           inorder.push_back(temp->data);
           temp = temp->right;
       }
       return inorder;
    }
};
