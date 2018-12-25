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
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(!root) return ans;
        stack<TreeNode*>s;
        
        TreeNode* curr = root;
        TreeNode* prev = NULL;
    
        while(!s.empty() || curr != NULL){
            
            // for each root, go left first then go right
            
            // go left
            if(curr){
                s.push(curr);
                curr = curr -> left;
            }
            else{ // left has been processed
                TreeNode* n = s.top(); // get root 
                // go right
                if(n -> right && (prev != n -> right)){ // prevent the right is pushed to stack again
                    curr = n -> right;
                    
                }
                // if there is no left node and n's right node has been visited
                // push the root value and pop.
                else{
                    ans.push_back(n -> val);
                    prev = n;
                    s.pop();
                }
            }
            

        }
        
        return ans;
    }
};
