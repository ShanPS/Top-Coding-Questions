/*
Problem: Given a singly linked list, determine if it is a palindrome.

link: https://leetcode.com/problems/palindrome-linked-list/
*/

class Solution {
    int numelements(ListNode* head) {
        int num = 0;
        while(head) {
            num++;
            head = head->next;
        }
        return num;
    }
public:
    bool isPalindrome(ListNode* head) {
        int n = numelements(head);
        bool isodd = n%2;
        stack<int> s;
        n = n/2;

        while(n) {
            s.push(head->val);
            head = head->next;
            n--;
        }
        if(isodd)
            head = head->next;
        while(head) {
            if(s.top() != head->val)
                return false;
            s.pop();
            head = head->next;
        }
        return true;
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