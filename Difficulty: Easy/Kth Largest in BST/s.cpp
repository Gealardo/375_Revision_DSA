/* Structure of a Binary Tree Node
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
    void find(Node*&root , int k,int &i,int &ans){
      if(i>k) return;    
      if(root==nullptr) return;
      //right
      find(root->right,k,i,ans);
      //root
      if(i==k) ans=root->data;
      i++;
      //left
      find(root->left,k,i,ans);
    
    }
    int kthLargest(Node *root, int k) {
     int ans = -1;
     int i=1;
     find(root,k,i,ans);
     return ans;
    }
};
