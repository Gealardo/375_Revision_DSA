/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/rotate-doubly-linked-list-by-p-nodes/1
 * Platform     : GFG
 * Difficulty   : Easy
 */

#include <bits/stdc++.h>
using namespace std;

/* Structure of a doubly link list node
class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int x)
    {
        data = x;
        prev = nullptr;
        next = nullptr;
    }
};
*/

class Solution {
  public:
    Node *rotateDLL(Node *head, int k) {
       if(head==nullptr) return nullptr;
       if(head->next==nullptr) return head;
       Node* begin = head;
       Node*t = head;
       for(int i=1;i<k;i++){
           t=t->next;
           if(t==nullptr) return head;
       }
       Node*h = t->next;
       if(h==nullptr) return head;
       t->next = NULL;
       h->prev=NULL;
       Node*temp = h;
       while(temp->next!=nullptr){
            temp=temp->next;
       }
       temp->next = begin;
       return h;
    }
};
