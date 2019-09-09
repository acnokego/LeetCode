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
    /*
     * Complexity: O(n),
     * Space: O(n)
     * Using dfs to build the graph and then use bfs to traverse.
     */
    void buildGraph(TreeNode* root, unordered_map<int, vector<int>>& edges){
        if(root -> right){
            edges[root -> val].push_back(root -> right -> val);
            edges[root -> right -> val].push_back(root -> val);
            buildGraph(root -> right, edges);
        }
        if(root -> left){
            edges[root -> val].push_back(root -> left -> val);
            edges[root -> left -> val].push_back(root -> val);
            buildGraph(root -> left, edges);
        } 
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        unordered_map<int, vector<int>>edges;
        buildGraph(root, edges);
        vector<int>ans;
        if(!K){
            ans.push_back(target -> val);
            return ans;
        }
        
        // bfs
        queue<int>q;
        unordered_set<int>visited;
        visited.insert(target -> val);
        // push dis == 1
        for(int node : edges[target -> val]){
            q.push(node);
        }
        
        int curr_d = 1, level_size = q.size(), curr_size = 0, next_level_size = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            visited.insert(node);
            
            if(K == curr_d) {
                ans.push_back(node);
            }
            
            for(int edge : edges[node]){
                if(!visited.count(edge)){
                    q.push(edge);
                    ++next_level_size;
                }
            }
            
            ++curr_size;
            if(curr_size == level_size){
                if(K == curr_d) return ans;
                level_size = next_level_size;
                next_level_size = 0;
                curr_size = 0;
                ++curr_d;
            }
            
        }
        return ans;
    }
};
