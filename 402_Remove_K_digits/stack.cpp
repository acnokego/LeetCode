class Solution {
  /*
   * Complexity: O(n)
   * Space: O(n)
   */
public:
    string removeKdigits(string num, int k) {
        stack<char>left_char;
        string ans;
        for(char& d : num){
            // pop the character that is bigger than the current number
            // the number in the stack are of increasing order
            // we want the significant digits to be small and the least
            // significant to be big
            while(k > 0 && !left_char.empty() && (left_char.top() > d)){
                --k;
                left_char.pop();
            }
            left_char.push(d);
        }
        // to fix case like 11111 or 12345
        while(k > 0){
            --k;
            left_char.pop();
        }
        // pop the char to the ans string
        while(!left_char.empty()){
            ans += left_char.top();
            left_char.pop();
        }
        // handle ans with 0 length
        if(!ans.length()) return string({"0"});
        // remove leading 0s
        for(int i = ans.length() - 1; i >= 1; --i){
            if(ans[i] != '0') break;
            else ans.pop_back();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
