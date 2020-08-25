/*
Problem: You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.

Note:
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

link: https://leetcode.com/problems/add-two-numbers/
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = (l1->val + l2->val) / 10;
        ListNode* ptr = new ListNode((l1->val + l2->val) % 10);
        ListNode* head = ptr;
        
        l1 = l1->next; l2 = l2->next;
        while(l1 && l2) {
            ptr->next = new ListNode((l1->val + l2->val + carry) % 10);
            carry = (l1->val + l2->val + carry) / 10;
            ptr = ptr->next;
            l1 = l1->next; l2 = l2->next;
        }
        while(l1) {
            ptr->next = new ListNode((l1->val + carry) % 10);
            carry = (l1->val + carry) / 10;
            ptr = ptr->next;
            l1 = l1->next;
        }
        while(l2) {
            ptr->next = new ListNode((l2->val + carry) % 10);
            carry = (l2->val + carry) / 10;
            ptr = ptr->next;
            l2 = l2->next;
        }
        if(carry)
            ptr->next = new ListNode(1);
        
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