/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
/*
 * Complexity: O(n)
 * Space: O(1)
 * if faster pointer catch up with the slower one, there is a cycle.
 */
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next==NULL){
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(slow != fast) {
            if(fast == NULL || fast->next == NULL) {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};
