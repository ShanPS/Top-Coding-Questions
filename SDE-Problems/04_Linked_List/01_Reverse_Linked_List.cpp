/*
Problem: Reverse a singly linked list

link: https://leetcode.com/problems/reverse-linked-list/
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        
        ListNode* first = head;
        ListNode* second = head->next;
        first->next = NULL;
        while(second) {
            ListNode* temp = second->next;
            second->next = first;
            first = second;
            second = temp;
        }
        head = first;
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