/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/rotate-a-linked-list/1
 * Platform     : GFG
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

/* Linked List Node Structure
class Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
}; */

class Solution {
  public:
    Node* rotate(Node* head, int k) {
        Node*add = head;
        int n=0;
        Node* temp=head;
        while(temp!=nullptr){
            temp=temp->next;
            n++;
        }
        int x = k%n;
        Node*temp2=head;
        if(x==0) return head;x--;
        while(x--){
            temp2=temp2->next;
        }
        Node* newHead = temp2->next;
        Node*temp3 = newHead;
        while(temp3->next!=NULL) temp3=temp3->next;
        temp2->next=nullptr;
        temp3->next = add;
        return newHead;
    }
};
