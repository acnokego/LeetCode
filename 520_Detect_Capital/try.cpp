class Solution {
  /*
   * Complexity: O(l)
   * Space: O(1)
   */
public:
    bool isCapital(char c){
        return (c - 'A') <= 25 && (c - 'A') >= 0;
    }
    bool detectCapitalUse(string word) {
        
        int l = word.length();
        int cap_count = 0;
        
        for(int i = 0; i < l; ++i){
            if(isCapital(word[i])){
                if(i != 0 && !cap_count){
                    return false;
                }
                ++cap_count; 
            }
        }
        
        return !cap_count || (cap_count == 1) || (cap_count == l);
    }
};
