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
 * Space: O(h) the height of the tree
 */
class Solution {
public:
    // return the length consider the current node
    int dfs_helper(TreeNode* node, int& max_length) {
        int left = (node -> left) ? dfs_helper(node -> left, max_length ) : 0;
        int right = (node -> right) ? dfs_helper(node -> right, max_length): 0;
        int p_left = (node -> left && node -> left -> val == node -> val) ? left + 1 : 0;
        int p_right = (node -> right && node -> right -> val == node -> val) ? right + 1 : 0;
        
        // for current node the max_length consider the node would be p_left + p_right
        max_length = max(max_length, p_left + p_right);
        return max(p_left, p_right);
    }
    int longestUnivaluePath(TreeNode* root) {
        int max_length = 0;
        if(root) dfs_helper(root,  max_length);
        return max_length;
    }
};
