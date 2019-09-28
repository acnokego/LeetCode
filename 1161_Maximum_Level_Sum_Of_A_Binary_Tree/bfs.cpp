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
   * Complexity: O(V+E)
   * Space: O(V)
   */
public:
    int maxLevelSum(TreeNode* root) {
        pair<int, int>ans = make_pair(0, 0);
        
        
        queue<TreeNode*>q;
        q.push(root);
        int curr_num = 0, curr_sum = 0, curr_level = 1, level_num = 1, next_level_num = 0;
        while(!q.empty()){
            TreeNode* n = q.front();
            q.pop();
            ++curr_num;
            curr_sum += n -> val;
            
            if(n -> left) {
                q.push(n -> left);
                ++next_level_num;
            }
            if(n -> right){
                q.push(n -> right);
                ++next_level_num;
            }
            
            if(curr_num == level_num){
                curr_num = 0;
                level_num = next_level_num;
                if(ans.second < curr_sum){
                    ans.first = curr_level;
                    ans.second = curr_sum;
                }
                ++curr_level;
                curr_sum = 0;
                next_level_num = 0;
            }
        }
        return ans.first;
    }
};
