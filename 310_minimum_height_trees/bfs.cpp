class Solution {
  /*
   * Complexity: O(E + V) bfs
   * Space: O(E + V)
   */
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if(n == 1) return vector<int>({0});
        
        vector<unordered_set<int>>v_edges(n);
        
        for(auto& p : edges){
            v_edges[p.first].insert(p.second);
            v_edges[p.second].insert(p.first);
        }
        
        vector<int>leaves;
        for(int i = 0 ; i < n; ++i){
            if(v_edges[i].size() == 1){
                leaves.push_back(i);
            }
        }

        // start from ends(leaves)
        // find the nodes they meet and the nodes 
        // are the roots we want (the middle point of the path)
        while(n > 2){
            
            // remove leaves
            n -= leaves.size();
            vector<int>new_leaves;
            for(int& l : leaves){
                for(auto neighbor : v_edges[l]){
                    // remove the leaves from each neighbor
                    v_edges[neighbor].erase(l);
                    if(v_edges[neighbor].size() == 1){
                        new_leaves.push_back(neighbor);
                    }
                }
            }
            leaves = new_leaves;
        }
      
        return leaves;
    }
};
