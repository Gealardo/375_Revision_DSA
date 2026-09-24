/* Binary Tree Node Structure
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    void find(Node* root ,int l, int h, int &count){
        if(root==nullptr) return;
        // left
        find(root->left,l,h,count);
        //root
        if(root->data >= l && root->data <= h) count++;
        //right
        find(root->right,l,h,count);
    }
    int getCount(Node *root, int l, int h) {
      int count =0;
      find(root,l,h,count);
      return count;
    }
};