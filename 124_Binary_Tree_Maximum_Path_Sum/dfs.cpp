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
    // returm the maximum sum path starting from the root and ending at the node under the root
    int recursive(TreeNode* root, int& max_value){
        if(!root) return 0;
        
        // if the path is negative, do not go through that way
        int left = max(0, recursive(root -> left, max_value));
        int right = max(0, recursive(root -> right, max_value));
        // find the maximum path considering both left and right
        max_value = max(max_value, left + right + root -> val);
        return max(left, right) + root -> val;
        
    }
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int max_value = INT_MIN;
        recursive(root, max_value);
        return max_value;
    }
};
