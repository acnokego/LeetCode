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
 * Space: O(n)
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(!root) return ans;
        
        stack<TreeNode*>s;
        s.push(root);
        
        // root -> left -> right
        while(!s.empty()){
            TreeNode* curr = s.top();
            s.pop();
            
            // root
            ans.push_back(curr -> val);
            // push right first
            if(curr -> right != NULL) s.push(curr -> right);
            // push left last, and left out first
            if(curr -> left != NULL) s.push(curr -> left);
        }
        
        return ans;
    }
};
