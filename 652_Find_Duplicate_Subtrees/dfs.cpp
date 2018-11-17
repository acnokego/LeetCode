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
 * Space: O(lg(n))
 */
class Solution {
public:
    string dfs(TreeNode* root, unordered_map<string, int>& hash, vector<TreeNode*>& ans){
        if(root == NULL) return "#";
        string post_structure = dfs(root -> right, hash, ans) + "," + dfs(root->left, hash, ans) + 
            "," + to_string(root->val);
        if(!hash.count(post_structure)){
            hash[post_structure] = 1;
        }
        else if(hash[post_structure] == 1){
            ans.push_back(root);
            hash[post_structure] = 2;
        }
        return post_structure;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> hash;
        vector<TreeNode*>ans;
        dfs(root, hash, ans);
        return ans;
    }
};
