/* Binary Tree Node Structure
class Node {
    public:
    int data;
     Node *left;
     Node *right;
     Node *next;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    void in(Node*root,vector<Node*>&ar){
        if( root == nullptr) return;
        in(root->left,ar);
        // root
        ar.push_back(root);
        in(root->right,ar);
    }
    void populateNext(Node *root) {
        if(root==nullptr) return;
        vector<Node*>ar;
        in(root,ar);
        int n= ar.size();
        for(int i=0;i<n-1;i++){
           ar[i]->next = ar[i+1]; 
        }
        ar[n-1]->next = nullptr;
        
        return;
    }
};