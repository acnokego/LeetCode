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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int max_depth = 0;
        while(!q.empty()){
            ++ max_depth;
            int tmp_size = q.size();
            for(int i = 0; i < tmp_size; ++i){
                TreeNode* n = q.front();
                q.pop();
                if(n -> left != NULL) q.push(n -> left);
                if(n -> right != NULL) q.push(n -> right);
            }
        }
        return max_depth;
    }
};
