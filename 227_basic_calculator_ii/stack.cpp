class Solution {
  /*
   * Complexity: O(n) the length of the string
   * Space: O(n)
   * reference:
   * https://leetcode.com/problems/basic-calculator-ii/discuss/63006/C++-stack-solution.
   */
public:
    bool isDigit(char c){
        return ((c - '0') <= 9 && (c - '0') >= 0);
    }
    int calculate(string s) {
        int ans = 0;
        int tmp_num = 0;
        // last op
        char sign = '+';
        stack<int>S;
        int l = s.length();
        for(int i = 0; i < l; ++i){
            // isDigit
            if(isDigit(s[i])){
                tmp_num = tmp_num*10 + (s[i] - '0');
            }
            // nonDigit
            if(i == l-1 || (!isDigit(s[i]) && s[i] != ' ')){
                if(sign == '+') S.push(tmp_num);
                else if(sign == '-') S.push(-tmp_num);
                else{
                    int num = S.top();
                    if(sign == '*') num *= tmp_num;
                    else num /= tmp_num;
                    S.pop();
                    S.push(num);
                }
                sign = s[i];
                tmp_num = 0;  
            }
        }
        while(!S.empty()){
            int num = S.top();
            ans += num;
            S.pop();
        }
        return ans;
    }
};
