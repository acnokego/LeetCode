class Solution {
public:
    /*
     * Complexity: O(l1*l2)
     * Space: O(l1)
     */
    int findRotateSteps(string ring, string key) {
        unordered_map<char, vector<int>>occur_idx;
        
        for(int i = 0; i < ring.length(); ++i){
            occur_idx[ring[i]].push_back(i);
        }
        
        vector<int>prev_moves(ring.length(), INT_MAX); 
        // the minimum moves to the previous character in key (key[i-1])
        
        // for the first character
        for(int idx: occur_idx[key[0]]) {
            // get the min_distance between the curr_idx and the starting_idx
            int distance = min(idx - 0, int(ring.length()) - idx);
            prev_moves[idx] = 1 + distance;
        }
          
        for(int i = 1; i < key.length(); ++i){
            vector<int>curr_moves(ring.length(), INT_MAX);
            // only assign the values to the idx that are equal to key[i]
            for(int idx : occur_idx[key[i]]){
                for(int prev_idx : occur_idx[key[i-1]]){
                // get the min_distance between the curr_idx and the starting_idx (idx of key[i-1])
                    int distance = min(abs(idx - prev_idx), int(ring.length()) - abs(idx - prev_idx));
                    curr_moves[idx] = min(curr_moves[idx], prev_moves[prev_idx] + distance + 1);
                }
            }
            // update the value of the prev_moves
            prev_moves = curr_moves;
        }
        int ans = INT_MAX;
        for(int last_idx : occur_idx[key.back()]){
            ans = min(ans, prev_moves[last_idx]);
        }
        return ans;
    }
};
