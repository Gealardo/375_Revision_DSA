/* The Node structure is
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    Node* makebst(int val,Node*&roott){
        if(roott==nullptr){
          roott = new  Node(val);    
          return  roott;
        }   
        if(roott->data>val){
           roott->left=makebst(val,roott->left);
        }
        else{
           roott->right=makebst(val,roott->right);
        }
        return roott;
    }
    void traverse(Node* root,Node*&roott){
        if(root==nullptr) return;
        traverse(root->left,roott);
        makebst(root->data,roott);
        traverse(root->right,roott);
    }
    Node *binaryTreeToBST(Node *root) {
       Node* roott=nullptr;
       traverse(root,roott);
       return roott; 
    }
};
