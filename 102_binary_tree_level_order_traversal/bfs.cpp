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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode* > q;
        q.push(root);
        int level_size = 1;
        while(!q.empty()){
            vector<int>level;
            // record the number of elements in next level
            int new_level_size = 0;
            // only iterate for the element in this level
            for(int i = 0; i < level_size; ++i){
                TreeNode* node = q.front();
                // push the level element
                level.push_back(node -> val);
                q.pop();
                if(node -> left != NULL){
                    q.push(node->left);
                    ++new_level_size;
                }
                if(node -> right != NULL){
                    q.push(node->right);
                    ++new_level_size;
                }
            }
            ans.push_back(level);
            level_size = new_level_size;
        }
        return ans;
    }
};
