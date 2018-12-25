class Solution {
  /*
   * Complexity: O(n)
   * Space: O(1)
   */
public:
    bool canTransform(string start, string end) {
        int pos_s1 = 0, pos_s2 = 0;
        int s1 = start.length(), s2 = end.length();
        if(s1 != s2) return false;
        while(pos_s1 < s1 && pos_s2 < s2){
            // find the non-x value
            while(pos_s1 < s1 && start[pos_s1] == 'X') ++pos_s1;
            while(pos_s2 < s2 && end[pos_s2] == 'X') ++pos_s2;
            // the rest of strings are all 'X'
            if(pos_s1 == s1 && pos_s2 == s2) return true;
            // one of the string reach to the end
            if(pos_s1 == s1 || pos_s2 == s2) return false;
            // L -> R or R -> L
            if(start[pos_s1] != end[pos_s2]) return false;
            // L -> L but end is on the right of the start
            if(start[pos_s1] == 'L' && pos_s2 > pos_s1) return false;
            // R-> R  but end is on the left of the start
            if(start[pos_s1] == 'R' && pos_s1 > pos_s2) return false;
            ++pos_s1;
            ++pos_s2;
        }
        return true;
    }
};
