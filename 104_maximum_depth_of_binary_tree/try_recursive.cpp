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
 * get the depth from right and left then return the bigger one.
 * Complexity: O(n)
 * Space: O(n) worst-case for a singly linked list, Avg: O(height)
 * Only care about the stack frames at a time not total.
 */
class Solution {
public:
    // return the max depth if take this node as root
    int DFS(TreeNode* node, int tmp_depth) {
        ++tmp_depth;
        int left, right;
        left = right = tmp_depth;
        if(node -> left != NULL){
            left = DFS(node -> left, tmp_depth);
        }
        if (node -> right != NULL){
            right = DFS(node -> right, tmp_depth);
        }
        return max(left, right);
        
    }
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return DFS(root, 0);
    }
};
