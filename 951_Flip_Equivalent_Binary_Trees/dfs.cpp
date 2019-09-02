class Solution {
public:
    /*
     * Complexity: O(n)
     * Space: O(h)
     */
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(!root1 || !root2) {
            return root1 == root2;
        }
        if(root1 -> val == root2 -> val){
            bool flip_equal = flipEquiv(root1 -> left, root2 -> right) && flipEquiv(root1 -> right, root2 -> left);
            bool non_flip_equal = flipEquiv(root1 -> left, root2 -> left) && flipEquiv(root1 -> right, root2 -> right); 
            if(flip_equal || non_flip_equal) return true;
        }
        return false;
    }
};
