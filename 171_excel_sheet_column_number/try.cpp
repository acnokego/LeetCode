class Solution {
  /*
   * Complexity: O(n)
   * Space: O(1)
   */
public:
    int titleToNumber(string s) {
        int n = s.length();
        int ans = 0;
        int digit = 1;
        for(int i = n-1; i >= 0; --i){
            ans += (s[i]-'A'+ 1) * digit;
            digit *= 26;
        }
        return ans;
    }
};
