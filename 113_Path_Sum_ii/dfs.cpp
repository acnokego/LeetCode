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
 * Space: O(h)
 */
class Solution {
public:
    void recursive(vector<vector<int>>& ans, vector<int>& path, TreeNode* n, int sum){
        path.push_back(n -> val);
        
        // if it is a leaf
        if(n -> left == NULL && n -> right == NULL && sum == n -> val){
            ans.push_back(path);
        }
        if(n -> left != NULL){
            recursive(ans, path, n -> left, sum - n -> val);
        }
        if(n -> right != NULL){
            recursive(ans, path, n -> right, sum - n -> val);
        }
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>>ans;
        if(!root) return ans;
        
        vector<int>path;
        recursive(ans, path, root, sum);
        return ans;
        
    }
};
