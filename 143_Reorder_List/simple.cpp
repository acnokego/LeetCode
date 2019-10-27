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
    void reorderList(ListNode* head) {
        if(head == NULL || head -> next == NULL) return;
        ListNode* mid = head;
        ListNode* end = head -> next;
        while(end -> next != NULL && end -> next -> next !=NULL){
            mid = mid -> next;
            end = end -> next -> next;
        }
        // reverse the second half of the list
        end = mid -> next;
        mid -> next = NULL;
        
        ListNode* prev = NULL;
        while(end != NULL){
            ListNode* tmp_next = end -> next;
            end -> next = prev;
            if(tmp_next == NULL){
                break;
            }
            prev = end;
            end = tmp_next;
        }
        // reorder
        prev = NULL;
        // first half list (head ptr)
        // and the second half reversed list (end ptr)
        while(head != NULL && end != NULL){
            if(prev != NULL){
                // connect Ln to L1
                prev -> next = head;
            }
            ListNode * head_next = head -> next;
            head -> next = end; // connect L0 to Ln
            prev = end;
            head = head_next;
            end = end -> next;
        }
        
        if(head != NULL && prev != NULL){
            prev -> next = head;
        }
    }
};
