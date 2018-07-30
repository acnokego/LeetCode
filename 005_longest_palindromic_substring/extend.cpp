class Solution {
  /*
   * Complexity : O(n^2) but less than dp, we only have to check until s[st] !=
   * s[en]
   * Space: O(1)
   * Reference: 
   * https://leetcode.com/problems/longest-palindromic-substring/discuss/2928/Very-simple-clean-java-solution
   */
private:
    int start = 0, max_len = INT_MIN;
public:
    void extendAroundCenter(string s, int st, int en){
        while(st >= 0 && en < s.length() && s[st] == s[en]){
            --st;
            ++en;
        }
        if(en - st - 1 > max_len){
            start = st + 1;
            max_len = en - st - 1;
        }
        
    }
    string longestPalindrome(string s) {
        int n = s.length();
        if(n < 2) return s;
        for(int i = 0; i < n; ++i){
            extendAroundCenter(s, i, i); // center of odd string
            extendAroundCenter(s, i, i+1); //center of even string
        }
        return s.substr(start, max_len);
    }
};
