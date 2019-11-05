class Solution {
public:
    /*
     * Complexity: O(m+n)
     * Space: O(n)
     */
    vector<int>kmpProcess(string pattern){
        int n = pattern.length();
        vector<int>arr(n, 0);
        // len can be viewd as the length of matched prefix/suffix.
        // complexity: O(n)
        for(int i = 1, len = 0; i < n;){
            // prefix = suffix til 0...len
            if(pattern[i] == pattern[len]){
                ++len;
                arr[i] = len;
                ++i;
            } else if(pattern[i] != pattern[len] && len != 0){
                //we will check the index of previous
                //possible prefix
                len = arr[len - 1];
            } else {
                // len = 0, move to the next letter
                arr[i] = 0;
                ++i;
            }
        }
        return arr;
    }
    int strStr(string haystack, string needle) {
        int m = haystack.length(), n = needle.length();
        if(!n){
            return 0;
        }
        // complexity: O(m), j would be increament at most m time and decrease m time -> O(2m)
        vector<int>lps = kmpProcess(needle); //longest prefix suffix.
        for(int i = 0, j = 0; i < m;){
            if(haystack[i] == needle[j]){
                ++i;
                ++j;
                if(j == n){
                    return i - j;
                }
            } else {
                if(j == 0){
                    ++i; // starting again to match the pattern
                } else {
                    j = lps[j-1]; // move the to the next character of prefix that already match to continue match.
                }
            }
        }
        return -1;
        
    }
};
