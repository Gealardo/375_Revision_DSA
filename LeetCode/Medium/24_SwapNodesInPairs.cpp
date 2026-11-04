/**
 * Problem Link : https://leetcode.com/problems/swap-nodes-in-pairs/
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
    
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* front = nullptr;
        int n = 2;
        while(curr!=NULL && n>0){
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front; n--;
        }
        if(front){
            head->next = swapPairs(front);
        }
        return prev;
    }
};
