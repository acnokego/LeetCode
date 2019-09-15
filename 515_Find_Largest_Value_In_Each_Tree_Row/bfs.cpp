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
    /*
     * Complexity: O(n)
     * Space: O(n)
     */
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*>q;
        vector<int>ans;
        if(!root) return ans;
        
        int max_value = INT_MIN, curr_num = 0, layer_num = 1, next_layer = 0;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* n = q.front();
            q.pop();
            max_value = max(max_value, n -> val);
  
            if(n -> left){
                q.push(n -> left);
                ++next_layer;
            }
            if(n -> right){
                q.push(n -> right);
                ++next_layer;
            }
            
            ++curr_num;
            if(curr_num == layer_num){
                curr_num = 0;
                layer_num = next_layer;
                next_layer = 0;
                ans.push_back(max_value);
                max_value = INT_MIN;
            }
            
        }
        return ans;
    }
};
