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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy= new ListNode(-1); ListNode* connector=dummy;
        ListNode* t1=list1; ListNode*t2=list2;
        while(t1!=NULL && t2!=NULL){
            if(t1->val < t2->val){
                ListNode* newNode=new ListNode(t1->val); t1=t1->next;
                connector->next=newNode;
                connector=newNode;
            }
            else{
                ListNode* newNode=new ListNode(t2->val); t2=t2->next;
                connector->next=newNode;
                connector=newNode;
            }
        }
        while(t1!=NULL) {
            ListNode* newNode=new ListNode(t1->val); t1=t1->next;
            connector->next=newNode;
            connector=newNode;
        }
        while(t2!=NULL){
            ListNode* newNode=new ListNode(t2->val); t2=t2->next;
            connector->next=newNode;
            connector=newNode;
        }
        return dummy->next;
    }
};
