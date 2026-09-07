/* Structure of Linked List Node
class Node {
 public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        int len=0;
        if(head==nullptr || head->next==nullptr) return len;
        Node* slow=head;
        Node* fast=head;    
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                break;
            }
        }
        if (fast == nullptr || fast->next == nullptr) {
                  return 0;
        }

        fast=fast->next; len++;
        while(fast!=slow){
            fast=fast->next;
            len++;
        }
        return len;
    }
};