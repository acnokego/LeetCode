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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(!root) return ans;
        queue<TreeNode*>q;
        q.push(root);
        
        int curr_num = 0, level_num = 1, next_num = 0;
        
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            
            ++curr_num;
            
            if(curr -> left){
                q.push(curr -> left);
                ++next_num;
            }
            if(curr -> right){
                q.push(curr -> right);
                ++next_num;
            }
            
            // visited all nodes in the current level
            if(curr_num == level_num){
                ans.push_back(curr -> val);
                curr_num = 0;
                level_num = next_num;
                next_num = 0;
            }
        }
        
        return ans;
        
    }
};
