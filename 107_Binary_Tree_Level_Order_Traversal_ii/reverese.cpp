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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>ans;
        int curr_level_num = 1, curr_num = 0, next_level_num;
        vector<int>level;
        
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* n = q.front();
            q.pop();
            if(n != NULL){
                level.push_back(n -> val);
                q.push(n -> left);
                q.push(n -> right);
                next_level_num += 2;
                
            }
            ++curr_num;
            if(curr_num == curr_level_num){
                curr_num = 0;
                curr_level_num = next_level_num;
                next_level_num = 0;
                if(level.size()) ans.push_back(level);
                level = vector<int>();
            }
            
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};
