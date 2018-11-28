class Solution {
  /*
   * Complexity: O(n^2) TLE
   * Space: O(n)
   */
public:
    int dfs(vector<vector<int>>& edges, int start, vector<bool>& visited){
        visited[start] = true;
        
        int depth = INT_MIN;
        for(int n : edges[start]){
            if(!visited[n]){
                int tmp_d = dfs(edges, n, visited);
                depth = (tmp_d > depth) ? tmp_d : depth;
            }
        }
        depth = (depth == INT_MIN) ? 0 : (depth + 1);
        return depth;
    }
    
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int>ans;
        
        vector<vector<int>>v_edges(n);
        
        for(auto& p : edges){
            v_edges[p.first].push_back(p.second);
            v_edges[p.second].push_back(p.first);
        }
        
        int min_height = INT_MAX;
        
        unordered_map<int, vector<int>> heights;
        // for each root;
        for(int i = 0; i < n; ++i){
            
            vector<bool>visited(n, false);
            int tmp_depth = dfs(v_edges, i, visited);
            min_height = (tmp_depth < min_height) ? tmp_depth : min_height;
            heights[tmp_depth].push_back(i);
        }
        
        return heights[min_height];
    }
};
