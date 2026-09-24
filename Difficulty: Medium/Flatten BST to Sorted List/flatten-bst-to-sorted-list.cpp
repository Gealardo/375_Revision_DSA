/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    void in(Node*root,vector<Node*>&LL){
        if(root == nullptr) return;
        // left
        in(root->left,LL);
        // root
        LL.push_back(root);
        // right
        in(root->right,LL);
    }
    Node *flattenBST(Node *root) {
        // code here
        vector<Node*>LL;
        in(root,LL);
        int n=LL.size();
        for(int i=0;i<n-1;i++){
            LL[i]->left = nullptr;
            LL[i]->right = LL[i+1];
        }
        LL[n-1]->left=nullptr; LL[n-1]->right = nullptr;
        return LL[0];
    }
};