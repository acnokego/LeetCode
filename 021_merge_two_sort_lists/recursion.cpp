/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
 * Complwxity: O(n)
 * Space: O(n) number of stack frames
 *
 * This solution is not a tail-recursive (do the calculation first, then
 * recursion, passing the result as parameters.) 
 * the stack will overflow while the list is too long :)
 * http://en.wikipedia.org/wiki/Tail_call
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        if(l1 -> val < l2 -> val){
            l1 -> next = mergeTwoLists(l1 -> next, l2);
            return l1;
        }
        else{
            l2 -> next = mergeTwoLists(l1, l2 -> next);
            return l2;
        }     
    }
};
