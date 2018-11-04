/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
 * Complexity: O(1) avg. Each node would be pushed into stack only once. 
 * Space: O(h)
 */
class BSTIterator {
private: 
    stack<TreeNode*>depth;
public:
    BSTIterator(TreeNode *root) {
        TreeNode* n = root;
        while(n != NULL){
            depth.push(n);
            n = n -> left;
        }
        
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (depth.size() > 0);
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* ans = depth.top();
        depth.pop();
        TreeNode* n = ans -> right;
        while( n != NULL){
            depth.push(n);
            n = n -> left;
        }
        return ans -> val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
