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
 * Memorize all ancestors from root to the target node in an array space;
 * Then compare two array's value to find the lowest common ancestor.
 */
class Solution {
public:
    bool dfs_des_arr(TreeNode* node, vector<TreeNode*>& arr, int target){
        arr.push_back(node);
        if(node -> val == target) return true;
        bool found = false;
        if(node -> left != NULL){
            if(dfs_des_arr(node -> left, arr, target)) found = true;
        }
        if(node -> right != NULL){
            if(dfs_des_arr(node -> right, arr, target)) found = true;
        }
        if(found) return true;
        else{
            arr.pop_back();
            return false;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        vector<TreeNode*> arr_p;
        vector<TreeNode*> arr_q;
        dfs_des_arr(root, arr_p, p -> val);
        dfs_des_arr(root, arr_q, q -> val);
        int p_s = arr_p.size();
        int q_s = arr_q.size();
        TreeNode* ans;
        for(int i = 0; i < min(p_s, q_s); ++i){
            if(arr_p[i] -> val != arr_q[i] -> val) break;
            ans = arr_p[i];
        }
        return ans;
    }
};
