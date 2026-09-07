/* Structure of Linked List Node
class Node {
 public:
    int data ;
    Node *next ;

    Node(int x) {
        data = x ;
        next = nullptr ;
    }
};
*/

class Solution {
  public:
    Node* reverseList(Node* head) {
       Node* curr=head;
       Node* prev=NULL;
       while(curr!=NULL){
           Node* front=curr->next;
           curr->next=prev;
           prev=curr;
           curr=front;
       }
       return prev;    
    }
};