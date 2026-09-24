/* Structure of binary tree Node 
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    int h(Node*&root,int &d){
        if(root==nullptr) return 0;
        int left =h(root->left,d);
        int right =h(root->right,d);
        d=max(d,left+right);
        return 1+max(left,right);
    }
    int diameter(Node* root) {
        int d=0;
        h(root,d);
        return d;
    }
};