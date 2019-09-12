class Solution {
public:
    /*
     * Complexity: O(n), number of bricks
     * Space: O(l), width of the wall
     *
     * Use the hashmap to record the number of bricks end at each positions.
     */
    int leastBricks(vector<vector<int>>& wall) {
        int rows = wall.size();
        unordered_map<int, int>edge_count;
        
        for(auto &row: wall){
            int pos = 0;
            for(int j = 0; j < row.size() - 1; ++j) {
                pos += row[j];
                edge_count[pos] += 1;
            }
        }
        
        int max_edge = 0;
        for(auto it = edge_count.begin(); it != edge_count.end(); ++it){
            max_edge = max(max_edge, it -> second);
        }
        return rows - max_edge;
    }
};
