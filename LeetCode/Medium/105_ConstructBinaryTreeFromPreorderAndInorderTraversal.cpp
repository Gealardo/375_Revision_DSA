/**
 * Problem Link : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int search(int x,vector<int>&inorder){
        int n= inorder.size();
        int r=-1;
        for(int i=0;i<n;i++){
            if(inorder[i]==x) return i;
        }
        return r;
    }
    TreeNode* construct(int &i,int n,int l,int h,vector<int>& preorder, vector<int>& inorder){
        if(i>n || l>h) return nullptr;
        TreeNode* root = new TreeNode(preorder[i]);
        int r = search(preorder[i],inorder);
        i++;
        if(i<n) root->left = construct(i,n,l,r-1,preorder,inorder);
        if(i<n) root->right = construct(i,n,r+1,h,preorder,inorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n= preorder.size(); int i=0;
        TreeNode* root = construct(i,n,0,n,preorder,inorder);
        return root; 
    }
};
