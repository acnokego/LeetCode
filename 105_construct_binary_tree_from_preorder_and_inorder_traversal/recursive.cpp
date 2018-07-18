/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//reference: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/discuss/34562/Sharing-my-straightforward-recursive-solution
class Solution {
public:
    TreeNode* recursive(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie){
        if(ps > pe) return NULL;
        TreeNode* node = new TreeNode(preorder[ps]); // one of the root
        int pos;
        // find the root that separate left subtree and right subtree
        for(int i = is; i <= ie; ++i){
            if(inorder[i] == node -> val){
                pos = i;
                break;
            }
        }
        // the left subtree has (pos -1 - is) + 1 elements
        node -> left = recursive(preorder, inorder, ps+1, ps + (pos - 1 - is + 1), is, pos - 1);
        // the right subtree has (ie - pos - 1) + 1 elements
        node -> right = recursive(preorder, inorder, pe - (ie - pos -1 + 1) + 1, pe, pos + 1, ie);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return recursive(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
};
