class Solution {
  /*
   * Complexity: O(n)
   * Space: O(1)
   */
public:
    bool judgeCircle(string moves) {
        unordered_map<char, pair<int, int>>move_cal({
            {'L', {-1, 0}}, {'R', {1, 0}}, {'U', {0, 1}}, {'D', {0, -1}}
        });
        pair<int, int>pos = make_pair(0, 0);
        
        for(int i = 0; i < moves.length(); ++i){
            pair<int, int>move = move_cal[moves[i]];
            pos.first += move.first;
            pos.second += move.second;
            
            
        }
        if(!pos.first && !pos.second) return true;
        return false;
        
    }
};
