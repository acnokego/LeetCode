class Solution {
public:
    /*
     * Complexity: O(N)
     * Space: O(1)
     */
    int knightDialer(int N) {
        vector<vector<int>>prev_move{{4,6}, {6,8}, {7,9}, {4,8}, {0,3,9}, {}, {0,1,7}, {2,6},{1,3},{2,4}};
        vector<long>move_count(10, 1);
        for(int i = 1; i <= N-1; ++i){
            vector<long>new_move_count(10);
            for(int i = 0; i <= 9; ++i){
                for(int j = 0; j < prev_move[i].size(); ++j){
                    new_move_count[i] += move_count[prev_move[i][j]];          
                }
                new_move_count[i] %= int(1e9 + 7);
            }
            move_count = new_move_count;
        }
        long total = 0;
        for(int i = 0; i <= 9; ++i){
            total += move_count[i];
            total %= int(1e9 + 7);
        }
        return total;
    }
};
