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

    void transformTree(Node *root) {
        
        int prev_sum = 0;
        stack<Node*>st;
        Node* t1 = root;
        
        while(t1!=NULL || !st.empty()){
            
            while(t1!=NULL){
                st.push(t1);
                t1=t1->right;
            }
            
            t1 = st.top();
            st.pop();
            
            //process root;
            int curr_val = t1->data;
            t1->data  = prev_sum;
            prev_sum+=curr_val;
            t1 = t1->left;
            
        }
        
        
    }
};
