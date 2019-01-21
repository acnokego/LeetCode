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
 * Complexity: O(n^2)
 * Space: O(h)
 */
class Solution {
public:
    
    int pathSumFrom(TreeNode* root, int sum){
        if(!root) return 0;     
        return (root -> val == sum ? 1 : 0) + pathSumFrom(root -> left, sum - root -> val) + pathSumFrom(root -> right, sum - root -> val);
    }
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        return pathSumFrom(root, sum) + pathSum(root -> left, sum) + pathSum(root -> right, sum);
    }
};
