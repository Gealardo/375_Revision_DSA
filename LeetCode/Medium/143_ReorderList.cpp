/**
 * Problem Link : https://leetcode.com/problems/reorder-list/
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

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
    void reorderList(ListNode* head) {
        ListNode* mid = head;
        ListNode* tail = head;
        while( tail!=nullptr && tail->next!=nullptr ){
          mid=mid->next;
          tail=tail->next->next;
        }
        ListNode* curr = mid->next;
        mid->next=nullptr;
        ListNode* prev=nullptr;
        while(curr!=nullptr){
            ListNode*front=curr->next;
            curr->next = prev;
            prev=curr;
            curr=front;
        }
        ListNode* b = prev;
        ListNode* a = head;
        while(b!=nullptr){
            ListNode* front1 = a->next;
            ListNode* front2 = b->next;
            a->next = b;
            b->next = front1;
            a = front1; b = front2; 
        }
        return;
    }
};
