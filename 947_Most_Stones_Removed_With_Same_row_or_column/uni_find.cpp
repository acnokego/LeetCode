class Solution {
public:
    /*
     * Complexity: O()
     * Space: O(n)
     */
    int groups;
    int removeStones(vector<vector<int>>& stones) {
        groups = 0;
        unordered_map<int, int>group_root;
        for(int i = 0; i < stones.size(); ++i){
            uni(stones[i][0], 10000 + stones[i][1], group_root);
        }
        return stones.size() - groups;
    }
    
    int find(int n, unordered_map<int, int>& group_root){
        if(group_root.find(n) == group_root.end()){
            ++groups;
            group_root[n] = n; // assign itself as the root of the group
        }
        // update the root
        if(group_root[n] != n) {
            group_root[n] = find(group_root[n], group_root);
        }
        return group_root[n];
    }
    void uni(int x, int y, unordered_map<int, int>& group_root){
        int g_x = find(x, group_root);
        int g_y = find(y, group_root);
        
        // add the root of x to the group of y
        if(g_x != g_y){
            group_root[g_x] = g_y;
            --groups;
        }
    }
};
