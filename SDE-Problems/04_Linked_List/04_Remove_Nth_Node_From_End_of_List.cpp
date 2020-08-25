/*
Problem: Given a linked list, remove the n-th node from the end of list and return its head.

link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *ptr1 = head, *ptr2 = head;
        
        for(int i=0; i<n; i++) 
            ptr1 = ptr1->next;
        
        if(ptr1 == NULL) return head->next;
        
        while(ptr1->next) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        ptr2->next = ptr2->next->next;
        return head;
    }
};

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