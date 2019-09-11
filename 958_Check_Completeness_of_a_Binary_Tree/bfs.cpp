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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*>q;
        bool end_of_push = false;
        q.push(root);
        
        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if(curr -> left && curr -> right){
                if(end_of_push) return false;
                q.push(curr -> left);
                q.push(curr -> right);
            } else if(!curr -> left && curr -> right){
               return false;
            } else if(curr -> left && !curr -> right){
                if(end_of_push) return false;
                q.push(curr -> left);
                // end of pushing child
                end_of_push = true;
            } else {
                end_of_push = true;
            }
            
        }
        return true;
        
    }
};
