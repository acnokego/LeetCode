class Solution {
  /*
   * Complexity: O(2^n * n) worst case: "aaaa...a" : 2^n. n: isPalin
   * Space: O(n) stack
   */
public:
    bool isPalin(string s){
        int n = s.length();
        for(int i = 0; i < (n/2); ++i){
            if(s[i] != s[n-1-i]) return false;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<string>> ans;
        if(n == 0) return ans;
        if(n == 1){
            vector<string>tmp(1, s);
            ans.push_back(tmp);
            return ans;
        }
        for(int i = n-1; i >= 0; --i){
            // substring from the end, if s[i...n-1] is palindrom
            string sub = s.substr(i);
            if(isPalin(sub)){
                vector<vector<string>> tmp_ans;
                // to get all possible partitions from s[0...i-1]
                tmp_ans = partition(s.substr(0, i));
                int tmp_size = tmp_ans.size();
                // if there is no partition push s[i...n]
                if(!tmp_size){
                    tmp_ans.push_back(vector<string>(1, sub));
                }
                // else for each partitions push s[i...n]
                else{
                    for(int j = 0; j < tmp_size; ++j){
                        tmp_ans[j].push_back(sub);
                    }
                }
                // insert these partitions to current answer
                ans.insert(ans.end(), tmp_ans.begin(), tmp_ans.end());
            }
        }
        return ans;
    }
};
