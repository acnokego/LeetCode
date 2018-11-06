class Solution {
  /*
   * Complexity: O(E*N) // to merge the union
   * Space: O(N)
   */
public:
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int,int>union_idx;
        vector<int>ans;
        // key: number, value: union-number
        union_idx[edges[0][0]] = 0;
        union_idx[edges[0][1]] = 0;
        int u_count = 1;
        for(int i = 1; i < edges.size(); ++i){
            auto u1 = union_idx.find(edges[i][0]);
            auto u2 = union_idx.find(edges[i][1]);
            if(u1 == union_idx.end() && u2 == union_idx.end()){
                union_idx[edges[i][0]] = u_count;
                union_idx[edges[i][1]] = u_count;
                ++u_count;
            }
            else if(u1 == union_idx.end()){
                // assign to the same union
                int u2_idx = u2 -> second;
                union_idx[edges[i][0]] = u2_idx;
                
            }
            else if(u2 == union_idx.end()){
                // assign to the same union
                int u1_idx = u1 -> second;
                union_idx[edges[i][1]] = u1_idx;
            }
            else{
                if(u1 -> second == u2 -> second){
                    ans = vector<int>({edges[i][0], edges[i][1]});
                }
                else{
                    int mod_idx = u2 -> second;
                    // merge the union
                    for(auto it = union_idx.begin(); it != union_idx.end(); ++it){
                        if(it -> second == mod_idx){
                            it -> second = u1 -> second;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
