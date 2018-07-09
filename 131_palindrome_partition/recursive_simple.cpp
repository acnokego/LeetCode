class Solution {
  /*
   * Complexity: O(2^n * n) n for check palindrom
   * Space: O(n) stack
   */
public:
    bool isPalin(const string& s, int start, int end){
        int n = end - start + 1;
        for(int i = 0; i < (n/2); ++i){
            if(s[start + i ] != s[end - i]) return false;
        }
        return true;
    }
    void backtrack(int index, string& s, vector<string>& path, vector<vector<string>> & ret ){
        if(index == s.size()){
            ret.push_back(path);
            return;
        }
        for(int i = index; i < s.size(); ++i){
            // s[index...i] is palidrom
            if(isPalin(s, index, i)){
                path.push_back(s.substr(index, i - index + 1));
                // check s[i+1...n]
                backtrack(i + 1, s , path, ret);
                // pop s[index...i] and try s[index ... i+1] at next iter
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> path;
        vector<vector<string>> ans;
        if(!s.length()) return ans;
        backtrack(0, s, path, ans);
        return ans;
    }
    
};
