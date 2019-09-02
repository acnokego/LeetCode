/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    /*
     * Complexity: O(n)
     * Space: O(h)
     *
     * If the pruned substree is NULL means that there is no 1 in that subtree.
     * We only have to pruned the current node when it's 0 and it's subtrees are
     * all pruned (no 1 under it).
     */
    TreeNode* pruneTree(TreeNode* root) {
        if(!root) return root;
        root -> left = pruneTree(root->left);
        root -> right = pruneTree(root->right);
        if(!root -> val && !root -> left && !root -> right) return NULL;
        else return root;
    }
};
