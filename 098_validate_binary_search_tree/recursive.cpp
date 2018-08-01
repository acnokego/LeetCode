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
 * Complexity: O(n) number of nodes
 * Space: O(n) worst-case stack frames (single linked)
 */
class Solution {
public:
    bool validSubBst(TreeNode* root, TreeNode* min, TreeNode* max){
        if((max && !(root -> val < max -> val)) || ( min && !(root -> val > min -> val)))  return false;
        if(root -> left != NULL){ 
            if(!(root -> val > root -> left -> val) || !validSubBst(root -> left, min, root)) return false;
        }
        if(root -> right != NULL){
            if(!(root -> val < root -> right -> val) || !validSubBst(root -> right, root, max) ) return false;
        }
        return true;
    
    }
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        if(root -> left != NULL){ 
            if(!(root -> val > root -> left -> val) || !validSubBst(root -> left, NULL, root)) return false;
        }
        if(root -> right != NULL){
            if(!(root -> val < root -> right -> val) || !validSubBst(root -> right, root, NULL)) return false;
        }
        return true;
    }
};
