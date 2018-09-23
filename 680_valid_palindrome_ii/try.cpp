class Solution {
  /*
   * Complexity: O(n)
   * Space: O(1)
   */
public:
    bool checkPalindrome(const string&s ,int start, int end){
        int len = end - start + 1;
        int half = len / 2;
        for(int i = 0; i < half; ++i){
            if(s[start + i] != s[end - i]) return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int len = s.length();
        int half = len / 2;
        for(int i = 0; i < half; ++i){
            if(s[i] != s[len-1-i]){
                // discard the left letter
                if(checkPalindrome(s, i+1, len-1-i)) return true;
                else if(checkPalindrome(s, i, len-2-i)) return true;
                else return false;
            }
        }
        return true;
    }
};
