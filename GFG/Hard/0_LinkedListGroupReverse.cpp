/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1
 * Platform     : GFG
 * Difficulty   : Hard
 */

#include <bits/stdc++.h>
using namespace std;

/* Structure of linked list Node
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = nullptr;
    }
};*/

class Solution {
  public:
   
    Node *reverseKGroup(Node *head, int k) {
       // step1 rev k node
       Node* curr= head;
       Node*front=NULL;
       int count=0;
       Node*prev=nullptr;
       while(curr !=NULL && count<k){
           front = curr->next;
           curr->next=prev;
           prev=curr;
           curr=front;
           count++;
       }
       //step2 recurtion for other node;
       if(front!=nullptr){
           head->next = reverseKGroup(front,k);
       }
       // return head of rev list
       return prev;
    }
};
