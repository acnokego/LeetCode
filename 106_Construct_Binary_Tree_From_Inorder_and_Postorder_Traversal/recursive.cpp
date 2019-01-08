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
     TreeNode* helper(int post_start, int in_start, int in_end, vector<int>& postorder, vector<int>& inorder){
        if(post_start >= 0 || in_start > in_end){
            return NULL;
        }
        
        int in_root = in_start;
        
        while(inorder[in_root] != postorder[post_start] && in_root <= in_end){
            ++in_root;
        }
        
        TreeNode* root = new TreeNode(postorder[post_start]);
        
        root -> left = helper(post_start - (in_end - in_root) - 1, in_start, in_root - 1, postorder, inorder);
        root -> right = helper(post_start - 1, in_root + 1, in_end, postorder, inorder);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(postorder.size() - 1, 0, inorder.size() - 1, postorder, inorder);
    }
};
