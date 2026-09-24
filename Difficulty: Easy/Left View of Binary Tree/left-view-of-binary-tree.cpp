/* Structure of Binary Tree Node
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
    vector<int> leftView(Node *root) {
       vector<int>ans;
       if(root==nullptr) return ans;
       queue<Node*>q;
       q.push(root);
       while(!q.empty()){
           int n=q.size();
           ans.push_back(q.front()->data);
           for(int i=0;i<n;i++){
               Node* temp=q.front();
               q.pop();
               if(temp->left!=nullptr) q.push(temp->left);
               if(temp->right!=nullptr) q.push(temp->right);
           }
       }
        return ans;
    }
};