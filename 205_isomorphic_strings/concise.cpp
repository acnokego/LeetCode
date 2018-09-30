class Solution {
public:
    bool isIsomorphic(string s, string t) {
         int m1[256] = {0}, m2[256] = {0}, n = s.size();
        for (int i = 0; i < n; ++i) {
            // if the previos occurred index is different
            // both not occurred or occurred at the same index
            if (m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]] = i + 1; // store the index
            m2[t[i]] = i + 1; // store the index
        }
        return true;
    }
};
