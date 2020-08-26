/*
Problem: Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

Note:
1. k is a positive integer and is less than or equal to the length of the linked list.
2. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

link: https://leetcode.com/problems/reverse-nodes-in-k-group/
*/

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* current = head;
        ListNode* next = NULL;
        ListNode* prev = NULL;
        int count = 0;
        
        while(count < k) {
            if(current == NULL) return head;
            current = current->next;
            count++;
        }
        
        current = head; count = 0;
        while(count < k) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            count++;
        }

        if (current != NULL) 
            head->next = reverseKGroup(current, k);

        return prev;
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