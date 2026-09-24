/* Structure of Binary Tree Node
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
      vector<int>ans;
      if(root==NULL) return ans;
      queue<Node*>q;
      q.push(root);
      int i=0;
      while(!q.empty()){
          int n=q.size();
          vector<int>level;
          for(int i=0;i<n;i++){
              Node* curr=q.front();
              q.pop();
              level.push_back(curr->data);
              if(curr->left!=nullptr) q.push(curr->left);
              if(curr->right!=nullptr) q.push(curr->right);
          }
          if(i%2!=0){
              reverse(level.begin(),level.end());
          }
          for(auto &x:level){
              ans.push_back(x);
          }
          i++;
      }
      return ans;  
    }
};
