/* Structure of a Tree Node
class Node {
  public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
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
    Node* preToBST(vector<int>& pre) {
        Node* roott=nullptr;
        for(auto &x:pre) makebst(x,roott);
        return roott;
    }
};