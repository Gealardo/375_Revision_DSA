/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr) return head;
        int s = 0;
        ListNode* temp = head;
        while(temp!=nullptr){
            s++; temp=temp->next;
        }
        int x = s-n;
        // cases x<0 ---> node not exist
        if(x<0) return head;
        // case x = 0 ---> head need to delete
        if(x==0){
            ListNode* delnode = head;
            head=head->next;
            delete(delnode);
            return head;
        }
        // case x > 0 --> move just 1 less than x & u will be at prev
        ListNode* prev=head;
        for(int i=0 ; i<x-1 ;i++){
           prev = prev -> next;
        }
        prev->next = prev->next->next;
        return head;
    }
};
