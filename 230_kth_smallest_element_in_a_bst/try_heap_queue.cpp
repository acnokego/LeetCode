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
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int, vector<int>, greater<int> > pq;
        queue<TreeNode*>q;
        if(!root) return NULL;
        q.push(root);
        // bfs. push elements into pq: nlgn
        while(!q.empty()){
            TreeNode* node = q.front();
            pq.push(node -> val);
            if(node -> left != NULL) q.push(node -> left);
            if(node -> right != NULL) q.push(node -> right);
            q.pop();
        }
        // find the k small in pq: klgn
        for(int i = 0; i < k-1; ++i){
            pq.pop();
        }
        return pq.top();
    }
};
