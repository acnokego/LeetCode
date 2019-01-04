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
 * Complexity: O(lg(n)^2)
 * Space: O(lg(n))
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int height_l = 0, height_r = 0;
        
        TreeNode* l = root;
        TreeNode* r = root;
        
        while(l){
            ++height_l;
            l = l -> left;
        }
        
        while(r){
            ++height_r;
            r = r -> right;
        }
        
        if(height_l == height_r) return pow(2, height_l) - 1;
        
        return 1 + countNodes(root -> left) + countNodes(root -> right);
        
    }
};
