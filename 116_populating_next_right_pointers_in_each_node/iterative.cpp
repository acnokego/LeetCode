/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        // the first element of each level
        TreeLinkNode* next;
        while(root && root -> left){
            next = root -> left;
            // connect each level through the next pointer of previous level
            while(root){
                root -> left -> next = root -> right;
                root -> right -> next = (root -> next != NULL ? root -> next -> left : NULL);
                root = root -> next;
            }
            root = next;
        }
    }
};
