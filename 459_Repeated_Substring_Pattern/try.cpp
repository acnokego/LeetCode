class Solution {
  /*
   * Complexity: O(n^2)
   * Space: O(n)
   */
public:
    bool repeatedSubstringPattern(string s) {
        int start = 0, end = 0;
        // for each length of pattern
        while(end < (s.length() / 2)){
            // get the pattern with specific length
            string pattern = s.substr(start, end-start + 1);
            if(s.length() % pattern.length() == 0){
                bool matched = true;
                for(int i = end + 1; i < s.length(); i += pattern.length()){
                    if(s.substr(i, pattern.length()) == pattern) continue;
                    else{
                        matched = false;
                        break;
                    }
                }
                if(matched) return true;
            }
            ++end;
        }
        return false;
    }
};
