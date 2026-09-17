/* Node Structure
class Node {
  public:
    int data;
    Node* next;
    Node(int key) {
        data = key;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    int generat_num(Node*head){
      long long num=0;
      long long mod=1000000007;   
      while(head!=NULL){
          num = (num*10 + head->data)%mod;
          head=head->next;
      }
      return int(num);
    }
    int multiplyTwoLists(Node* first, Node* second) {
        // code here
        long long mod=1000000007;
        long long ans = ((long long)generat_num(first)*generat_num(second))%mod;
        return int(ans); 
    }
};
