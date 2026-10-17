/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/delete-without-head-pointer/1
 * Platform     : GFG
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

/* Structure of Linked List Node
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    void deleteNode(Node* x) {
       if(x->next==nullptr) delete(x);
       x->data = x->next->data;
       Node* del = x->next;
       Node* front = x->next->next;
       x->next = front;
       delete(del);
       return;
    }
};
