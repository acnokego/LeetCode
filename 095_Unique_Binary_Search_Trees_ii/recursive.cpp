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
 * Complexity: O(#ans*n) // can use cache to cache result
 * Space: O(n)
 */
class Solution {
public:
    vector<TreeNode*> connect(int idx, vector<TreeNode*> r, vector<TreeNode*> l){
        vector<TreeNode*> ans;
        for(int i = 0; i < r.size(); ++i){
            for(int j = 0; j < l.size(); ++j){
                TreeNode* n = new TreeNode(idx);
                n -> right = r[i];
                n -> left = l[j];
                ans.push_back(n);
            }
        }
        return ans;
    }
    
    // create subtrees for the range of number [start, end] 
    vector<TreeNode*> helper(int start, int end){
        if(start > end) return vector<TreeNode*>(1, NULL);
        
        vector<TreeNode*>ans;
        for(int i = start; i <= end; ++i){
            // left subtree combinations
            vector<TreeNode*>left = helper(start, i - 1);
            // right subtree combinations
            vector<TreeNode*>right = helper(i + 1, end);
            // connect all left/right subtrees with the root node
            vector<TreeNode*> res = connect(i, right, left);
            ans.insert(ans.end(), res.begin(), res.end());
        }
        
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return (n > 0) ? helper(1, n) : vector<TreeNode*>();
    }
};
