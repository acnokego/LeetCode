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
 *
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        
        int p_val = p -> val, q_val = q -> val;
        if(root -> val == p_val){
            return p;
        }
        else if(root -> val == q_val){
            return q;
        }
        
        int big_val = (p_val > q_val) ? p_val : q_val;
        int small_val = (p_val < q_val) ? p_val : q_val;
        
        if(root -> val < big_val && root -> val > small_val) return root;
        else if(root -> val > big_val) return lowestCommonAncestor(root -> left, p, q);
        else return lowestCommonAncestor(root -> right, p, q);
        
    }
};
