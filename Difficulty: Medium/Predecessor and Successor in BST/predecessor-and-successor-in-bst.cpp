/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
}; */

class Solution {
  public:
    void in(Node*&root,int key,Node*&succ,Node*&prev){
        if(root==nullptr) return;
        // left
        in(root->left,key,succ,prev);
        // root
        if(root->data >key ){
           if(succ==nullptr) succ=root;
        }
        if(root->data<key) prev=root;
        // right
        in(root->right,key,succ,prev);
        
    }
    vector<Node*> findPreSuc(Node* root, int key) {
        
       vector<Node*>ans;
       Node* prev=nullptr;
       Node* succ=nullptr;
       
       in(root,key,succ,prev);
       
       ans.push_back(prev);      
       ans.push_back(succ);  
            
       return ans;
    }
};