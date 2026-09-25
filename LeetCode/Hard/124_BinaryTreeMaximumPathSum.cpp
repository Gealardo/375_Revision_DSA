/**
 * Problem Link : https://leetcode.com/problems/binary-tree-maximum-path-sum/
 * Platform     : LeetCode
 * Difficulty   : Hard
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
    int sum(TreeNode*&root,int &m){
        if(root==nullptr) return 0;
        int left = max(0,sum(root->left,m));
        int right = max(0,sum(root->right,m));
        m =max(m, left+ right+root->val);
        return root->val + max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        if(root==nullptr) return 0;
        int m=INT_MIN;
        sum(root,m);
        return m;
    }
};
