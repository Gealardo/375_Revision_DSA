/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1
 * Platform     : GFG
 * Difficulty   : Easy
 */

#include <bits/stdc++.h>
using namespace std;

/* Structure of Doubly Linked List Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        Node* curr=head;
        Node*back=NULL;
        Node*front=NULL;
        while(curr!=NULL){
            front=curr->next;
            curr->next=back;
            curr->prev=front;
            back=curr;
            curr=front;
        }
        return back;
    }
};
// for reversing in k group
/* Structure of Doubly Linked List Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // if in k group lets say k=2;
        int k=2;
        Node* curr=head;
        Node*back=NULL;
        Node*front=NULL;
        int count=0;
        while(curr!=NULL && count<k){
            front=curr->next;
            curr->next=back;
            curr->prev=front;
            back=curr;
            curr=front;
            count++;
        }
        if(front!=nullptr){
            head->next = reverse(front);
        }
        return back;
    }
};
