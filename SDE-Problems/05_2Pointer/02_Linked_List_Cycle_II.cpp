/*
Problem: Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

link: https://leetcode.com/problems/linked-list-cycle-ii/
*/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while(fast) {
            fast = fast->next;
            if(fast) {
                slow = slow->next;
                fast = fast->next;
            }
            if(fast == slow) break;
        }
        if(fast == NULL) return NULL;

        int loopsize = 1;
        fast = fast->next;
        while(fast != slow) {
            loopsize++;
            fast = fast->next;
        }
        
        slow = head;
        while(fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }

        return fast;
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