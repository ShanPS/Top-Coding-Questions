/*
Problem: Given a non-empty, singly linked list with first node as head.
Return the middle node of the linked list. If there are two middle nodes, return the second middle node.

link: https://leetcode.com/problems/middle-of-the-linked-list/
*/

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* first = head;
        ListNode* second = head;
        while((*second).next != NULL) {
            second = (*second).next;
            first = (*first).next;
            if((*second).next != NULL)
                second = (*second).next;
        }
        return first;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */