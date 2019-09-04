class Solution {
public:
    /*
     * Complexity: O(l^2)
     * Space: O(1)
     */
    int count(const string& s, int start, int end) {
        int tmp_count = 0;
        while(start >= 0 && end < s.length() && s[start] == s[end]){
            --start;
            ++end;
            ++tmp_count;
        }
        return tmp_count;
    }
    int countSubstrings(string s) {
        int ans = 0;
        
        int l = s.length();
        for(int i = 0; i < l; ++i) {
            ans += count(s, i, i); // center of odd
            ans += count(s, i, i+1); // center of even
        }
        return ans;
    }
};
