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
 * Complexity: O(max(n, level^2))
 * Space: O(level)
 */
class Solution {
public:
    void make_level(vector<vector<int>>& ans, TreeNode* n , int level){
        if(n == NULL) return;
        if(level >= ans.size()){
            ans.insert( ans.begin(), vector<int>());
        }
        make_level(ans, n -> left, level + 1);
        make_level(ans, n -> right, level + 1);
        ans[ans.size() - 1 - level].push_back( n -> val);
        
        
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>ans;
        make_level(ans, root, 0);
        return ans;
        
    }
};
