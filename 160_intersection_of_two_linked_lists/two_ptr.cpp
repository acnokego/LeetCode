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
 * reference: https://leetcode.com/problems/intersection-of-two-linked-lists/solution/
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
        ListNode* pA = headA;
        ListNode* pB = headB;
        while(pA -> val != pB -> val){
            pA = pA -> next;
            pB = pB -> next;
            if(pA == NULL && pB == NULL) break;
            else if(pA == NULL){
                pA = headB;
            }
            else if (pB == NULL){
                pB = headA;
            }
        }
        return pA;
    }
};
