/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    vector<int> lot(Node*root,vector<int>&l){
        if(root==nullptr) return l;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            l.push_back(curr->data);
            if(curr->left!=nullptr) q.push(curr->left);
            if(curr->right!=nullptr) q.push(curr->right);
        }
        return l;
    }
    vector<int> levelOrder(Node *root) {
        vector<int>l;
        return lot(root,l);
    }
};