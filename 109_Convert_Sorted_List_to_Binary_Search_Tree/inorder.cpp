/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
 * Complexity: O(n)
 * Space: O(lg(n))
 */
class Solution {
public:
    TreeNode* helper(ListNode** head, int start, int end){
        if(start > end){
            return NULL;
        }
        int mid = (end - start) / 2 + start;
        
        TreeNode* left = helper(head, start, mid - 1);
        TreeNode* root = new TreeNode((*head) -> val);
        *head = (*head) -> next;
        TreeNode* right = helper(head, mid + 1, end);
        
        root -> left = left;
        root -> right = right;
        
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        
        ListNode* ptr = head;
        int size = 0;
        
        while(ptr != NULL){
            ++size;
            ptr = ptr -> next;
        }
        
        return helper(&head, 0, size - 1);
        
    }
};
