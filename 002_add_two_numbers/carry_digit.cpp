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
   * Complexity: O(max(len(l1), len(l2)))
   * Space: O(max(len(l1), len(l2)))
   */
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* prehead = new ListNode(0);
        ListNode* prev = prehead;
        int carry = 0;
        while(carry || l1 || l2){
            int val1 = (l1 ? l1 -> val : 0);
            int val2 = (l2 ? l2 -> val : 0);
            int sum = val1 + val2 + carry;
            carry = sum / 10;
            sum = sum % 10;
            ListNode* n = new ListNode(sum);
            prev -> next = n;
            prev = n;
            l1 = (l1 ? l1 -> next : l1);
            l2 = (l2 ? l2 -> next : l2);
        }
        return prehead -> next;
    }
};
