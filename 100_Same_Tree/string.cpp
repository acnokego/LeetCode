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
    void traverse(TreeNode* n, string& s){
        if(n == NULL){
            s += "null,";
            return;
        }
        // preorder
        s += (to_string(n -> val) + ",");
        traverse(n -> left, s);     
        traverse(n -> right, s);
        
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        string structure_p = "";
        string structure_q = "";
        
        traverse(p, structure_p);
        traverse(q, structure_q);

        return structure_p == structure_q;
        
    }
};
