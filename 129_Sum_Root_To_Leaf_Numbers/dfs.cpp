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
    void recursive(TreeNode* node, int& ans, int number){
        number = number * 10 + node -> val;
        if(!node -> right && !node -> left){
            ans += number;
        }     
        else{
            if(node -> left){
               recursive(node -> left, ans, number);
            } 
            if(node -> right){
                recursive(node -> right, ans, number);
            }
        }
    }
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        if(!root) return 0;
        recursive(root, ans, 0);
        return ans;
    }
};
