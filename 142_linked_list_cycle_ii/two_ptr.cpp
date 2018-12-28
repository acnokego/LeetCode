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
 *
 * For the first meeting points, we have 2x - x = n*l (x: meeting position, l: length of
 * the cycle).
 * Let's say the position of entry point is E. THe distance between the entry
 * point and the meeting point is m. We can have E = x - m = n*l - m = (n - 1)*l
 * + (l - m). We can then have the entry points by having the meeting
 * points between point starting from x and point starting from the start of the
 * list.
 
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
