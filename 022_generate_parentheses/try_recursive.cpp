class Solution {
  /*
   * Complexity: O(2^n) 
   * Space: O(n) stacks + O( number of solutions...)
   */
public:
    void backtrack(vector<string>& ans, string& tmp, int n, int left, int right){
        if(tmp.length() == n*2){
            ans.push_back(tmp);
            return;
        }
        // for each backtrack, check if we can append '(' or ')'
        // if the number of '(' is larger than ')' then we can append ')'
        if(left > right){
            tmp += ')';
            backtrack(ans, tmp, n, left, right+1);
            tmp.pop_back();
        }
        // if the number of '(' is less than n then we can append it.
        if(left < n){
            tmp += '(';
            backtrack(ans, tmp, n, left+1, right);
            tmp.pop_back();
        }

        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string tmp;
        if(n == 0) return ans;
        backtrack(ans, tmp, n, 0, 0);
        return ans;
    }
};
