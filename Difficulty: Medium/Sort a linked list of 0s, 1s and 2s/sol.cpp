class Solution {
  public:
    Node* segregate(Node* head) {
       if(head==NULL || head->next==NULL) return head;
       Node* temp=head;
       int c0=0; int c1=0; int c2=0;
       while(temp!=NULL){
           if(temp->data == 0) c0++;
           else if(temp->data == 1) c1++;
           else c2++;
           temp=temp->next;
       }
       temp = head;
       while(temp!=NULL){
           if(c0>0){
               temp->data = 0;
                c0--;
           }
           else if(c1>0){
               temp->data = 1;
               c1--;
           }
           else {
               temp->data = 2;
               c2--;
           }
           temp = temp->next;
       }
       return head;
    }
};
