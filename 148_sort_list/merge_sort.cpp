/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
 * Complexity: O(nlgn)
 * Space: O(n) (stack frames while merge the whole array, n/2 comparison)
 */
class Solution {
public:
    ListNode* merge(ListNode* h1, ListNode* h2){
        if(h1 == NULL) return h2;
        if(h2 == NULL) return h1;
        if(h1 -> val < h2 -> val){
            h1 -> next = merge(h1 -> next, h2);
            return h1;
        }
        else{
            h2 -> next = merge(h1, h2 -> next);
            return h2;
        }
    }
    ListNode* sortList(ListNode* head) {
        // base case
        if(head == NULL || head -> next == NULL) return head;
        
        ListNode* pre = head;
        ListNode* mid = head;
        ListNode* end = head;
        // find the mid
        while(end != NULL && end -> next != NULL){
            pre = mid;
            mid = mid -> next;
            end = end -> next -> next;
        }
        // separate two list
        pre -> next = NULL; 
        // h1: first half sorted list, h2: the second half sorted list 
        ListNode* h1 = sortList(head);
        ListNode* h2 = sortList(mid);
        
        return merge(h1, h2);
    }
};
