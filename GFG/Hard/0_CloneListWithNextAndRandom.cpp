/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1
 * Platform     : GFG
 * Difficulty   : Hard
 */

#include <bits/stdc++.h>
using namespace std;

/* Structure of Linked List Node
class Node {
  public:
    int data;
    Node* next;
    Node* random;

    Node(int x) {
        data = x;
        next = random = nullptr;
    }
};*/

class Solution {
  public:
   Node* makell(Node*head,unordered_map<Node*,Node*>&mp){
       Node* dummy = new Node(-1);
       Node* connect = dummy;
       Node* temp = head;
       while(temp!=nullptr){
           int val = temp->data;
           Node* newnode = new Node(val);
           mp[temp]=newnode;
           connect->next = newnode;
           connect = newnode;
           temp=temp->next;
       }
       return dummy->next;
   }
   Node* randu(Node*head){
       unordered_map<Node*,Node*>mp;
       Node* h2 = makell(head,mp);
       Node* temp2 = h2;
       Node* temp = head;
       while(temp!=nullptr){
           Node* r = temp->random;
           Node* cr = NULL;
           if(r) cr = mp[r];
           temp2->random = cr;
           temp=temp->next;
           temp2=temp2->next;
       }
       return h2;
   }
    Node* cloneLinkedList(Node* head) {
       if(head==nullptr) return nullptr;
       return randu(head);    
    }
};
