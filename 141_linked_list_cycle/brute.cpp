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
 * Complexity: O(n^2)
 * Space: O(n)
 */
public:
    bool hasCycle(ListNode *head) {
        std::vector<ListNode*>isPass;
        while(head != NULL) {
            head = head->next;
            if(std::find(isPass.begin(), isPass.end(), head) != isPass.end()){
                return true;
            }
            else{
                isPass.push_back(head);
            }
        }
        return false;
    }
};
