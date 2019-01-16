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
    pair<int, int>helper(TreeNode* root, int& ans){
        if(!root) return make_pair(0, 0);
        
        int root_include = 0;
        int root_not_include = 0;
        
        pair<int, int> left = helper(root -> left, ans);
        pair<int, int> right = helper(root -> right, ans);
        
        left.first = max(left.first, 0); left.second = max(left.second, 0);
        left.second = max(left.second, 0); right.second = max(right.second, 0);
        
        
        root_include = root -> val + left.second + right.second;
        root_not_include = max(left.first, left.second) + max(right.first, right.second);
        
        ans = (ans == INT_MIN) ? max(root_include, root_not_include) : max(root_include, max(root_not_include, ans));
        
        // return largest sum of subtree including root and not including root
        return make_pair(root_include, root_not_include);
    }
    
    int rob(TreeNode* root) {
        if(!root) return 0;
        int ans = INT_MIN;
        helper(root, ans);
        return ans;
    }
};
