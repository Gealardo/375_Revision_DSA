/**
 * Problem Link : https://leetcode.com/problems/split-linked-list-in-parts/
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>ans;
        int N = 0;
        ListNode* temp = head;
        while(temp!=nullptr){
            N++;
            temp = temp->next;
        }
        int size = 0; int rem = 0;
        temp = head;
        if(N < k){
            size = 1;
        }else if(N%k == 0){
            size = N/k;

        }else{
            rem = N%k;
            size = N/k;
        }
        ListNode* t1 = head;
        while(k--){
           if(t1!=nullptr) {
            ListNode* thead = t1;
            int x = size;
            while(x>1){
                t1 = t1->next;
                x--;
            }
            if(rem>0){
                t1= t1->next; rem--;
            }
            ListNode* front = t1->next;
            t1->next = nullptr;
            ans.push_back(thead);
            t1 = front;
           }else{
             ans.push_back(nullptr);
           }
        }
        return ans;

    }
};
