/* Structure of linked list Node
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
    void del(Node*&head,Node*&curr,Node*&prev,Node*&front){
        if(curr==head){
            Node* temp=curr;
            head=front;
            curr=front;
            front=front->next;
            delete(temp);
        }
        else{
            Node*temp=curr;
            prev->next=front;
            curr=front;
            if(front!=nullptr) front=front->next;
            delete(temp);
        }
    }
    Node* removeDuplicates(Node* head) {
        Node* prev=NULL;
        Node* curr=head;
        if(curr==NULL || curr->next==NULL) return head;
        unordered_map<int,int>mp;
        while(curr!=NULL){
            Node* front = curr->next;
            if(mp.find(curr->data)!=mp.end()){
                del(head,curr,prev,front);
                continue;
            }
            mp[curr->data]++;
            prev=curr; curr=front;
        }
       return head;
    }
};
