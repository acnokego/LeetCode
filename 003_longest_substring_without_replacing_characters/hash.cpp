class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        int max_length = 0;
        std::unordered_map<char, int>used_char;
        // std::vector<int>used_char(256, -1)
        // if char using ASCII, could use this vector as the hashmap
        // need to make sure start <= used_char[[s[i]]]
        // since the idx used_char[s[i]] may be smaller than the start due to other repeating chars
        for(int i = 0; i<s.length(); ++i){
            if(used_char.find(s[i]) != used_char.end() && start <= used_char[s[i]]){
                start = used_char[s[i]] + 1;
            }
            else{
                max_length = std::max(max_length, i-start+1);
            }
            used_char[s[i]] = i;
        }
        return max_length;
    }
};
