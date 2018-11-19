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
    void dfs_inorder(TreeNode* root, int& prev, int& ans){
        if(root -> left != NULL) dfs_inorder(root -> left, prev, ans);
        if(prev >= 0){
            ans = (abs(prev - root -> val) < ans) ? abs(prev - root -> val) : ans;
        }
        prev  = root -> val;
        if(root -> right != NULL) dfs_inorder(root -> right, prev, ans);
    }
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        int prev = -1;
        dfs_inorder(root, prev, ans);
        return ans;
    }
};
