class Solution {
  /*
   * Complexity: O(n)
   * Space: O(n)
   */
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int>occurrence;
        for(auto& c:s){
            occurrence[c] += 1;
        }
        for(auto& c:t){
            auto it = occurrence.find(c);
            if(it == occurrence.end()){
                return c;
            }
            else{
                if(--it -> second == 0){
                    occurrence.erase(it);
                }
            }
        }
    }
};
