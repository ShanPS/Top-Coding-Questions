/*
Problem: A linked list is given such that each node contains an additional random pointer which 
could point to any node in the list or null.
Return a deep copy of the list.

link: https://leetcode.com/problems/copy-list-with-random-pointer/
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        
        Node *ptr = head;
        while(ptr) {  // make a copy of current Node and place it just after the original Node
            Node *temp = new Node(ptr->val);
            temp->next = ptr->next;
            ptr->next = temp;
            ptr = ptr->next->next;
        }

        // Now update random pointer for copy Nodes as per its original
        ptr = head;
        while(ptr) {
            ptr->next->random = (ptr->random) ? ptr->random->next : NULL;
            ptr = ptr->next->next;
        }

        // Seperate original Nodes and copy Nodes
        Node *copyHead = head->next;  // head of copy Nodes
        Node *cptr = copyHead;
        ptr = head;
        while(ptr) {
            ptr->next = ptr->next->next;
            ptr = ptr->next;
            if(ptr) cptr->next = cptr->next->next;
            else cptr->next = NULL;
            cptr = cptr->next;
        }

        return copyHead;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/