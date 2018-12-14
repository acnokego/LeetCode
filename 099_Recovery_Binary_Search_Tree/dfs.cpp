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
    void recursive(TreeNode* n, TreeNode*& first, TreeNode*& second, TreeNode*& prev){
        if(n == NULL) return;
        
        
        recursive(n -> left, first, second, prev);
        if(prev != NULL && prev -> val > n -> val){
            // swap when prev > n
            if(first == NULL){
                first = prev;
                second = n;
            }
            // if there is also other element n < prev
            // much smaller than the previous second (must be)
            // since it gonna be swapped to the prev of the previous seoncd.
            else{
                // update the second
                second = n;
            }
        }
       
        prev = n;
        recursive(n -> right, first, second, prev);

    }
    void recoverTree(TreeNode* root) {
        TreeNode* first = NULL;
        TreeNode* second = NULL;
        TreeNode* prev = NULL;
        
        // in-order traverse
        recursive(root, first, second, prev);
        
        // swap the smaller one with the bigger one
        if(first != NULL && second != NULL){
            int tmp = first -> val;
            first -> val = second -> val;
            second -> val = tmp;
        }
        return; 
    }
};
