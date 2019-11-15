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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;
        ListNode* odd = head;
        if(head -> next == NULL){
            return head;
        }
        ListNode* even_head = head -> next;
        ListNode* even = even_head;
        
        bool isOdd = true;
        ListNode* curr = even_head -> next;
        while(curr != NULL){
            if(isOdd){
                odd -> next = curr;
                odd = curr;
            } else {
                even -> next = curr;
                even = curr;
            }
            curr = curr -> next;
            isOdd = !isOdd;
        }
        odd -> next = even_head;
        even -> next = NULL;
        return head;
    }
};
