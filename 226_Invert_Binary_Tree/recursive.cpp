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
 * Space: O(h)
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        // invert
        invertTree(root -> left);
        invertTree(root -> right);
        
        TreeNode* tmp = root -> left;
        root -> left = root -> right;
        root -> right = tmp;
        return root;
    }
};
