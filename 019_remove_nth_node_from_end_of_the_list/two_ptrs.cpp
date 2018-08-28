/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
 * Complexity: O(n) the length of the list
 * Space: O(1)
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* start = new ListNode(0);
        start -> next = head;
        ListNode* slow = start;
        ListNode* fast = start;
        // move the fast pointer to the nth pos from the head.
        for(int i = 1; i <= n; ++i){
            fast = fast -> next;
        }
        // the distance between fast and slow is n. thus, when fast reach the end, the slow would be in the l-n pos
        // then slow -> next would be the element that need to be removed
        while(fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next;
        }
        // removed the first element
        if(slow == start) return head -> next;
        slow -> next = slow -> next -> next;
        return head;     
    }
};
