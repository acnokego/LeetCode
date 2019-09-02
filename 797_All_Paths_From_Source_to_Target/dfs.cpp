class Solution {
public:
    /*
     * Complexity: O(V + E)
     * Space: O(V)
     */
    void dfs(vector<vector<int>>& ans, int node, vector<int>curr_path, const vector<vector<int>>& graph, vector<bool>& visited){
        curr_path.push_back(node);
        if(node == graph.size() - 1){
            ans.push_back(curr_path);
            return;
        }
        visited[node] = true;
        for(int e : graph[node]) {
            if(!visited[e]){
                dfs(ans, e, curr_path, graph, visited);
            }
        }
        visited[node] = false;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        if(!graph.size()) return ans;
        vector<bool>visited(graph.size(), false);
        vector<int>curr_path;
        
        dfs(ans, 0, curr_path, graph, visited);
        return ans;
    }
};
