/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  /*
   * Complexity: O(n)
   * Space: O(n)
   * like the way of the recursive, just using queue to traverse the tree.
   */
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*>bfs;
        bfs.push(root->left);
        bfs.push(root->right);
        while(!bfs.empty()){
            TreeNode* one = bfs.front();
            bfs.pop();
            TreeNode* two = bfs.front();
            bfs.pop();
            if(!one && !two ) continue;
            else if(!one || !two) return false;
            else if(one->val != two->val) return false;
            bfs.push(one->left);
            bfs.push(two->right);
            bfs.push(one->right);
            bfs.push(two->left);
        }
        return true;
    }
};
