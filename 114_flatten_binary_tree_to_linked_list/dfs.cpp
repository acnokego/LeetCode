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
 * Space: O(lgn) num of stacks
 */
class Solution {
public:
    TreeNode* dfs(TreeNode* n){
        TreeNode* end = NULL;
        TreeNode* ret_end = NULL;
        //cout << n -> val << endl;
        if(n -> left == NULL && n -> right == NULL) return n;
        // get the end node of the left
        if(n -> left != NULL) end = dfs(n -> left);
        ret_end = end;
        // get the end node of the right
        if(n -> right != NULL) ret_end = dfs(n -> right);
        // concat the right node to the end of the left 
        if(end != NULL){
            TreeNode* tmp = n -> right;
            n -> right = n -> left;
            n -> left = NULL;
            end -> right = tmp;
        }
        // return the end node of the right
        return ret_end;
    }
    void flatten(TreeNode* root) {
        if(!root) return;
        dfs(root);
    }
};
