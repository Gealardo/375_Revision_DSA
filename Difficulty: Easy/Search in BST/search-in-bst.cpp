/* Definition for Node
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
     
  public:
    bool find(Node*&root,int key){
        if(root==nullptr) return false;
        if(root->data==key) return true;
        bool left=false; bool right=false;
        if(root->data<key) right=find(root->right,key);
        if(root->data>key) left=find(root->left,key);
        return right|left;
    }
    bool search(Node* root, int key) {
    
        return find(root,key);
    }   
};