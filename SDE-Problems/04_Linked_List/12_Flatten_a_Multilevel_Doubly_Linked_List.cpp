/*
Problem: You are given a doubly linked list which in addition to the next and previous pointers, it could 
have a child pointer, which may or may not point to a separate doubly linked list. These child lists may have one or more children of their own, and so on, to produce a multilevel data structure.

Flatten the list so that all the nodes appear in a single-level, doubly linked list. You are given the head of the first level of the list.

link: https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
*/

class Solution {
    Node* getlastnode(Node* head) {
        while(head->next)
            head = head->next;        
        return head;
    }
public:
    Node* flatten(Node* head) {
        Node* cur = head;
        
        while(cur) {
            if(cur->child != NULL) {
                Node* child = cur->child;
                cur->child = NULL;
                
                Node* end = getlastnode(child);
                
                end->next = cur->next;
                if(cur->next)
                    cur->next->prev = end;
                cur->next = child;
                child->prev = cur;
            }
            cur = cur->next;
        }
        
        return head;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/