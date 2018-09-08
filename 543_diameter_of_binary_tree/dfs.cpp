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
 * Space: O(lgn)
 */
class Solution {
public:
    int longestPath(TreeNode* root, int& ans){
        if(!root) return 0;
        int left = longestPath(root -> left, ans);
        int right = longestPath(root -> right, ans);
        if((left + right) > ans) ans = left + right;
        return max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int ans = 0;
        int left = longestPath(root -> left, ans);
        int right = longestPath(root -> right, ans);
        return max(left + right, ans);
    }
};
