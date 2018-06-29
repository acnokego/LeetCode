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
 * Space: O(n) recursive stack + vector
 */
class Solution {
public:
    void recursive(TreeNode* Node, vector<int>& ans){
        if(Node->left != NULL) recursive(Node->left, ans);
        ans.push_back(Node->val);
        if(Node->right != NULL) recursive(Node->right, ans);
        
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root == NULL) return ans;
        recursive(root, ans);
        return ans;
    }
};
