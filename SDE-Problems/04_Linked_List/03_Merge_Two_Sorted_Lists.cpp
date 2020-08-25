/*
Problem: Merge two sorted linked lists and return it as a new sorted list.
The new list should be made by splicing together the nodes of the first two lists.

link: https://leetcode.com/problems/merge-two-sorted-lists/
*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        ListNode* node;
        if(l1->val < l2->val) {
            node = l1;
            node->next = mergeTwoLists(l1->next, l2);
        }
        else {
            node = l2;
            node->next = mergeTwoLists(l1, l2->next);
        }
        return node;
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