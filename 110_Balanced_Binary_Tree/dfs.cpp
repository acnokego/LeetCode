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
    int getHeight(TreeNode* n, bool & balanced){
        if(n == NULL) return 0;
        int left = getHeight(n -> left, balanced);
        int right = getHeight(n -> right, balanced);
        balanced = balanced && abs(left - right) <= 1;
        return max(left, right) + 1;
        
    }
    bool isBalanced(TreeNode* root) {
        
        bool ans = true;
        getHeight(root, ans);
        
        return ans;
        
    }
};
