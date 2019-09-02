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
     * Complexity: O(N * 2^N)
     * Space: O(2^N)
     */
    void helper(vector<TreeNode*>& ret, vector<TreeNode*>& left, vector<TreeNode*>& right) {
        for(auto l : left) {        
            for(auto r : right){
                TreeNode* root = new TreeNode(0);
                root -> left = l;
                root -> right = r;
                ret.push_back(root);
            }
        }
    }
    vector<TreeNode*> allPossibleFBT(int N) {
        // even nodes can never be full tree
        if(!N || N % 2 == 0) return vector<TreeNode*>();
        else if (N==1) return vector<TreeNode*>({new TreeNode(0)});
        vector<TreeNode*>ret;
        
        for(int i = 0; i <= (N-1) / 2; ++i){
            vector<TreeNode*>left = allPossibleFBT(i);
            vector<TreeNode*>right = allPossibleFBT(N-1-i);
            
            // check if its full bst
            if(left.size() && right.size()){
                helper(ret, left, right);
                if(i != (N-1) / 2) helper(ret, right, left);
            } 
        }
        return ret;
    }
};
