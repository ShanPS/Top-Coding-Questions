/*
Problem: You are given a linked list of N nodes.
The task is to remove the loop from the linked list, if present. 

Note: C is the position of the node to which the last node is connected. If it is 0 then no loop.

link: https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1
*/

// Floyd's cycle detection algorithm is used to solve this problem
void removeLoop(Node* head) {
    Node *slow = head, *fast = head;

    // check whether loop present or not
    while(fast) {
        fast = fast->next;
        if(fast) {
            slow = slow->next;
            fast = fast->next;
        }
        if(fast == slow) break;  // loop present
    }
    if(fast == NULL) return;  // no loop present
    
    // get the loop size (number of nodes in the loop)
    int loopsize = 1;
    fast = fast->next;
    while(fast != slow) {
        loopsize++;
        fast = fast->next;
    }
    
    fast = head;
    slow = head;
    while(--loopsize)
        fast = fast->next;
    while(fast->next != slow) {
        fast = fast->next;
        slow = slow->next;
    }    
    fast->next = NULL;
}