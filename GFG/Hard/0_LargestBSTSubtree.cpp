/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/largest-bst/1
 * Platform     : GFG
 * Difficulty   : Hard
 */

#include <bits/stdc++.h>
using namespace std;

/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class info{
   public:
     int mini;
     int maxi;
     int size;
     bool isBST;
};
class Solution {
  public:
    info solve(Node*root,int &ans){
	           if(root==nullptr){
	               return {INT_MAX,INT_MIN,0,true};
	           }
	          info left =  solve(root->left,ans);
	          info right =  solve(root->right,ans);

	           info currNode;

	           if(left.isBST && right.isBST && root->data > left.maxi && root->data < right.mini){
	               currNode.isBST = true;
	               currNode.size = left.size + right.size + 1;
	               currNode.mini = min(root->data,left.mini);
	               currNode.maxi = max(root->data,right.maxi);

	               ans = max(ans,currNode.size);

	           }else{
	               currNode.isBST = false;
	               currNode.size = 0;
	               currNode.mini = INT_MIN;
	               currNode.maxi = INT_MAX;
	           }

	          return  currNode;    
	       }

		int largestBst(Node* root){
			int ans = 0;
	           solve(root,ans);
	           return ans;
		}
    
};
