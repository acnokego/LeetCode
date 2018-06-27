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
 * reverse the pointing way
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *tmp;
        while(curr != NULL){
            tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
    
        return prev;
    }
};
