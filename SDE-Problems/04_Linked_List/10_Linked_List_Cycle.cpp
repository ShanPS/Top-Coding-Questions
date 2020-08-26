/*
Problem: Given a linked list, determine if it has a cycle in it.

link: https://leetcode.com/problems/linked-list-cycle/
*/

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast != NULL) {
            fast = fast->next;
            if(fast == NULL)  return false;
            if(fast == slow)  return true;
            slow = slow->next;
            fast = fast->next;
        }
        return false;
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