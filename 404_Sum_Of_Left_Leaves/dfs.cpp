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
    void helper(TreeNode* root, int& sum, bool left){
        if(!root) return;
        
        if(!root -> left && !root -> right && left){
            sum += root -> val;
            return;
        }
        
        helper(root -> left, sum, true);
        helper(root -> right, sum, false);
        
        
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        helper(root, sum, false);
        return sum;
    }
};
