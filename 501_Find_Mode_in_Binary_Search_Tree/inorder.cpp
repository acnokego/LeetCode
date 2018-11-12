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
 * Space: O(lgn) stack
 */
class Solution {
public:
    void findMax(TreeNode* n, int& max, int& temp_max, int& last_val){
        if(n -> left != NULL) findMax(n -> left, max, temp_max, last_val);
        if(last_val != n -> val){
            temp_max = 1;
            last_val = n -> val;
        }
        else{
            ++temp_max;
        }
        max = (temp_max > max) ? temp_max : max;
        if(n -> right != NULL) findMax(n -> right, max, temp_max, last_val);
        
    }
    void findMode(vector<int>& ans, TreeNode* n, const int& max, int& temp_max, int& last_val){
        if(n -> left != NULL) findMode(ans, n -> left, max, temp_max, last_val);
        if(last_val != n -> val){            
            temp_max = 1;
            last_val = n -> val;
        }
        else{
            ++temp_max;
        }
        if(temp_max == max) ans.push_back(last_val);
        if(n -> right != NULL) findMode(ans, n -> right, max, temp_max, last_val);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int>ans;
        if(!root) return ans;
        int max = 0, temp_max = 0, last_val = NULL;
        // in order traversal find Max occurrences first
        findMax(root, max, temp_max, last_val);
        temp_max = 0; last_val = NULL;
        // in order traversal find the modes with max occurrences.
        findMode(ans, root, max, temp_max, last_val);
        return ans;
    }
};
