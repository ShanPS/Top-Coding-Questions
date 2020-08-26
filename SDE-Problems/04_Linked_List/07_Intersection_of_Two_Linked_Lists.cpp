/*
Problem: Write a program to find the node at which the intersection of two singly linked lists begins.

Note:
1. If the two linked lists have no intersection at all, return null.
2. The linked lists must retain their original structure after the function returns.
3. You may assume there are no cycles anywhere in the entire linked structure.
4. Each value on each linked list is in the range [1, 10^9].
5. Your code should preferably run in O(n) time and use only O(1) memory.


link: https://leetcode.com/problems/intersection-of-two-linked-lists/
*/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int numA=0, numB=0;
        ListNode *ptr = headA;
        while(ptr != NULL) {
            numA++;
            ptr = ptr->next;
        }
        ptr = headB;
        while(ptr != NULL) {
            numB++;
            ptr = ptr->next;
        }
        
        while(numA > numB) {
            headA = headA->next;
            numA--;
        }
        while(numB > numA) {
            headB = headB->next;
            numB--;
        }
        
        for(int i=0; i<numA; i++) {
            if(headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
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