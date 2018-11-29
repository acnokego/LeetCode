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
    void dfs(vector<string>& ans, TreeNode* n, string& tmp){
        if(n -> left == NULL && n -> right == NULL){
            ans.push_back(tmp);
            return;
        }
        if(n -> left != NULL){
            string app = "->" + to_string(n -> left -> val);
            tmp += app;
            dfs(ans, n -> left, tmp);
            tmp.erase(tmp.length() - app.length(), app.length());
        }
        if(n -> right != NULL){
            string app = "->" + to_string(n -> right -> val);
            tmp += app;
            dfs(ans, n -> right, tmp);
            tmp.erase(tmp.length() - app.length(), app.length());
        }
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string tmp = "";
        if(root){
            tmp += to_string(root -> val);
            dfs(ans, root, tmp);
        }
        return ans;
    }
};
