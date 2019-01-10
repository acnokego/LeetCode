/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
 * Complexity: O(n)
 * Space: O(1)
 * the same method as 287
 * The distance between the starting point and the entry point is L1
 * The distance between the meeting point and the entry point is L2
 * The cycle length is C
 * For slow pointer: L1 + L2 + n1*C
 * For fast pointer: L1 + L2 + n2*C
 * -> 2(L1 + L2 + n1*C) = L1 + L2 +n2*C
 * -> L1 = (n2 - 2n1)C - L2 = n3*C - L2 
 
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return NULL;
        // Do different step first, assuming starting point lies in front of the
        // head.
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(slow != fast){
            slow = (slow->next != NULL ? slow->next : NULL);
            fast = (fast->next != NULL && fast->next->next != NULL ? fast->next->next : NULL);
            if(fast == NULL || slow == NULL) return NULL;
        }
        /*
         * started from the 0 -> head -> ...
         */
        fast = head;
        slow = slow -> next;
        while(fast != slow){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
