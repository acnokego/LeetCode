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
 *
 * Save each level in deque from left to right.
 * For each level, we checked the variable "left" to see whether we are going to
 * traverse from left or right.
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        deque<TreeNode*>level;
        level.push_back(root);
        int level_num = 1;
        // whether the next level should be traversed from left or not
        bool left = 0;
        while(!level.empty()){
            vector<int>tmp;
            int tmp_level_num = 0;
            for(int i = 0; i < level_num; ++i){
                // next level start from right
                if(!left){
                    // this level start from left
                    TreeNode* node = level.front();
                    tmp.push_back(node -> val);
                    level.pop_front();
                     if(node -> left != NULL){
                        level.push_back(node->left);
                        ++tmp_level_num;
                    }
                    if(node -> right != NULL){
                        level.push_back(node->right);
                        ++tmp_level_num;
                    }
                }
                // next level start from left
                else{
                    // this level start from right
                    TreeNode* node = level.back();
                    tmp.push_back(node -> val);
                    level.pop_back();  
                    if(node -> right != NULL){
                        level.push_front(node->right);
                        ++tmp_level_num;
                    }
                    if(node -> left != NULL){
                        level.push_front(node->left);
                        ++tmp_level_num;
                    }
                }

            }
            ans.push_back(tmp);
            left ^= 1;
            level_num = tmp_level_num;
        }
        return ans;
    }
};
