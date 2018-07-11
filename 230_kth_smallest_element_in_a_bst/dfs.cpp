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
     * Space: O(n) stacks
     * dfs traverse in order, return ans from the bottom.
     */
    int dfs(TreeNode* node, int& k){
        int ans = NULL;
        if(node -> left != NULL) ans = dfs(node->left, k);
        // we got ans return from the bottom
        if(ans != NULL) return ans;
        --k; 
        // if node is the kth
        if(k == 0) return node -> val;
        if(node -> right != NULL) ans = dfs(node->right, k);
        return ans;
    }
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return NULL;
        return dfs(root, k);
    }
};
