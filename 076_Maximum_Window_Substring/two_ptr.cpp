class Solution {
public:
    /*
     * Complexity: O(n)
     * Space: O(1)
     */
    string minWindow(string s, string t) {
        int start = 0, end = 0;
        string ans = "";
        int ans_len = INT_MAX, ans_start = 0, counter = t.length();
        unordered_map<char, int>t_count;
        for(char& c : t){
            t_count[c] += 1;
        }
        while(end < s.length()){
            // check if the curr char is in t, subtract its count in map.
            // if it is, minus the counter. 
            // advance the end.
            if(t_count[s[end]] > 0){
                --counter;
            }
            t_count[s[end]] -= 1;
            ++end;
            // match our constriction
            while(counter == 0){
                // update the max answer
                if((end - start) < ans_len) {
                    ans_len = end - start;
                    ans_start = start;
                }
                // move the start, add the previous subtract back
                // if encounter the char that was in t, add the counter back
                if(t_count[s[start]] == 0){
                    ++counter;
                }
                t_count[s[start]] += 1;
                ++start;
            }
        }
        return ans_len == INT_MAX ? string("") : s.substr(ans_start, ans_len);
    }
};
