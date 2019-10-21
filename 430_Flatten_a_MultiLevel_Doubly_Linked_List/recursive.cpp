/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    /*
     * Complexity: O(n)
     * Space: O(stack)
     */
    Node* recursive_tail(Node* head){
        Node* curr = head;
        while(curr != NULL){
            if(curr -> child != NULL){
                Node* tail = recursive_tail(curr -> child);
                Node* child_head = curr -> child;
                curr -> child = NULL;
                if(curr -> next != NULL){
                    curr -> next -> prev = tail;
                }
                tail -> next = curr -> next;              
                curr -> next = child_head;
                child_head -> prev = curr;
                if(tail -> next == NULL){
                    return tail;
                }
                curr = tail -> next;
            } else {
                if(curr -> next == NULL){
                    return curr;
                }
                curr = curr -> next;
            }

        }
        return curr;
    }
    
    Node* flatten(Node* head) {
        recursive_tail(head);
        return head;
    }
};
