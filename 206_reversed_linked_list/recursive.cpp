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
 * Space: O(n) stacks for the recursive call.
 * Assume from node nk+1 to nm had been reversed and you are at node nk.
 * n1 → … → nk-1 → nk → nk+1 ← … ← nm
 * We want nk+1’s next node to point to nk.
 * So,
 * nk.next.next = nk;
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* p = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return p;
    }
};
