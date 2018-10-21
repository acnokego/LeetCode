class Solution {
  /*
   * Complexity : O(n)
   * Space : O(n) depth of brackets
   */
public:
    // print characters in this bracket repeating k times
    void helper(string& ans, string& s, int& pos){
        if(pos >= s.length()) {
            return;    
        }
        
        int start_bracket = s.find("[", pos);
        int k = 1;
        if(start_bracket != string::npos) {
            k = stoi(s.substr(pos, start_bracket - pos + 1));
            pos = start_bracket + 1;
        }
        int start = pos;
        for(int i = 0; i < k; ++i) {
            while(pos < s.length() && s[pos] != ']'){
                if(isdigit(s[pos])) {
                    helper(ans, s, pos);
                }
                else {
                    ans += s[pos];
                    ++pos;
                }
            }
            // restore the position
            if(i != k-1) pos = start;
        }
        pos += 1;
    }
    string decodeString(string s) {
        string ans;
        if(!s.length()) return ans; 
        int pos = 0;
        while(pos < s.length()){
            if(isdigit(s[pos])) helper(ans, s, pos);
            else{
                ans += s[pos];
                ++pos;
            }
        }
        return ans;
    }
};
