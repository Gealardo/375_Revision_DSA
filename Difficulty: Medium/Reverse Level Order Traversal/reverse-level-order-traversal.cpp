/* Structure of Tree Node
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
    vector<int> lot(Node*root){
        vector<int>l;
        if(root==nullptr) return l;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            l.push_back(curr->data);
            if(curr->right!=nullptr) q.push(curr->right);
            if(curr->left!=nullptr) q.push(curr->left);
        }
        return l;
    }
    vector<int> reverseLevelOrder(Node *root) {
       vector<int>l = lot(root);
       reverse(l.begin(),l.end());
       return l;
    }
};