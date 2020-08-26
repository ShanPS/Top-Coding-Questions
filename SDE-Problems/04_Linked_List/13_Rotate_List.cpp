/*
Problem: Given a linked list, rotate the list to the right by k places, where k is non-negative.

link: https://leetcode.com/problems/rotate-list/
*/

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return NULL;
        
        int size = 1;  // Get the size of the linked list
        ListNode* ptr = head;
        while(ptr->next) {
            size++;
            ptr = ptr->next;
        }
        ptr->next = head;  // lastNode->next = head (To make it a circular linked list)

        k = k % size;  // Incase k is greater than the size
        
        // Make ptr to point to (size-k)th node so that there will be k nodes after that
        // (size-k)th node will be the last node after rotation
        ptr = head;
        for(int i=1; i<size-k; i++)
            ptr = ptr->next;
        
        // Now head will point to node after ptr 
        // and make ptr->next point to NULL (as ptr points to the last nodo after rotation)
        head = ptr->next;
        ptr->next = NULL;

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