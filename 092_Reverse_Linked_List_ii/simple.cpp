/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /*
     * Complexity: O(n)
     * Space: O(1)
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* prev = NULL;
        ListNode* start_prev = NULL;
        ListNode* start = head;
        ListNode* curr = head;
        int pos = 1;
        
        while(curr != NULL){
            if(pos == m){
                start_prev = prev;
                start = curr;
                prev = curr;
                curr = curr -> next;
            } else if (pos > m && pos < n) {
                ListNode* tmp_next = curr -> next;
                // reverse the next to its prev
                curr -> next = prev;
                prev = curr;
                curr = tmp_next;
            } else if (pos == n){
                // the start should connect to the next of the end
                start -> next = curr -> next;
                if(start_prev != NULL) start_prev -> next = curr;
                else head = curr;
                // reverse the end to its prev
                curr -> next = prev;
                break;
            } else{
                prev = curr;
                curr = curr -> next;
            }
            ++pos;
 
        }
        return head;
    }
};
