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
 * Space: O(n)
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return NULL;
        if(head -> next == NULL) return head;
        vector<int>val;
        val.push_back(head->val);
        ListNode *count = head;
        ListNode *point = head;
        while(count->next != NULL){
            count = count->next;
            val.push_back(count->val);
        }
        for(int i = 0; i < val.size(); ++i){
            point->val = val[val.size()-i-1];
            point = point->next;
        }
        return head;
    }
};
