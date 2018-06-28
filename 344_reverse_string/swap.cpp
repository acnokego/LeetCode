class Solution {
/*
 * Complexity: O(n)
 * Space: O(1) (modify the original string)
 * Swap the elements from the head and the one from the tail.
 */
public:
    string reverseString(string s) {
        if(s.length() == 0 || s.length() == 1) return s;
        int mid = s.length() / 2;
        char tmp;
        for(int i = 0; i < mid; ++i){
            tmp = s[i];
            s[i] = s[s.length()-1-i];
            s[s.length()-1-i] = tmp;
        }
        return s;
    }
};
