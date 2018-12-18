/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
/*
 * Complexity: O(n)
 * Space: O(h) // actually recursive call is not needed, using while instead
 */
class Solution {
public:
    void recursive(TreeLinkNode* prev_level){
        TreeLinkNode* next_start = NULL; // the start of the next level
        TreeLinkNode* prev = NULL; // tmp pointer to record the previous pointer
        
        // traverse the previous level using the next pointer
        while(prev_level != NULL){
            
            // get the start of the next level
            if(!next_start){
                if(prev_level -> left) next_start = prev_level -> left;
                else if(prev_level -> right) next_start = prev_level -> right;
            }
            
            // connect the children of the previous level 
            if(prev_level -> left && prev_level -> right){
                if(prev) prev -> next = prev_level -> left;
                prev_level -> left -> next = prev_level -> right;
                prev = prev_level -> right;
            }
            else if(prev_level -> left){
                if(prev) prev -> next = prev_level -> left;
                prev = prev_level -> left;
            }
            else if(prev_level -> right){
                if(prev) prev -> next = prev_level -> right;
                prev = prev_level -> right; 
            }
            
            prev_level = prev_level -> next;
        }
        
        if(next_start) recursive(next_start);
    }
    void connect(TreeLinkNode *root) {
        if(!root) return;
        recursive(root);
    }
};
