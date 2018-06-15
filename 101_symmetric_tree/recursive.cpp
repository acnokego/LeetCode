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
    bool is_subSymmetric(TreeNode* right, TreeNode* left) {
        if(right == NULL && left == NULL) return true;
        else if(right == NULL || left == NULL) return false;
        else if(right->val == left->val && is_subSymmetric(right->right, left->left) && is_subSymmetric(right->left, left->right)) return true;
        else return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return is_subSymmetric(root->right, root->left);
    }
};
