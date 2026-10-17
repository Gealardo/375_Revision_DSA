/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/replace-every-element-with-the-least-greater-element-on-its-right/1
 * Platform     : GFG
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct node{
        int val;
        node* left;
        node* right;
        node(int data){
            val = data;
            left = nullptr;
            right = nullptr;
        }
    };

    // Insert into BST and return the successor (least greater element)
    node* insert(node* root, int data, int &succ) {
        if (!root) {
            return new node(data);
        }
        if (data < root->val) {
            succ = root->val; // potential least greater
            root->left = insert(root->left, data, succ);
        } else {
            root->right = insert(root->right, data, succ);
        }
        return root;
    }

    vector<int> findLeastGreater(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        node* root = nullptr;

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {
            int succ = -1;
            root = insert(root, arr[i], succ);
            ans[i] = succ;
        }
        return ans;
    }
};

