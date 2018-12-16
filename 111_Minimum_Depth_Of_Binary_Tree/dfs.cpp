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
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int left = minDepth(root -> left);
        int right = minDepth(root -> right);
        
        // make sure its a leaf or there are nodes in both left and right
        if((!right && !left) || (right && left)){
            return 1 + min(left,right);
        }
        // if there is only one leaf of the child, select the path returned by it.
        else return 1 + ((!left) ? right : left);
    }
};
