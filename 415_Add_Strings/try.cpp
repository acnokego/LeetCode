class Solution {
  /*
   * Complexity: O(n)
   * Space: O(1)
   */
public:
    string addStrings(string num1, string num2) {
        char carry = '0';
        string ans;
        int pos1 = num1.length()-1, pos2 = num2.length() - 1;
        // calculate sum for digits from the last digit
        while(pos1 >= 0 && pos2 >= 0){
            int sum = (num1[pos1] - '0' + num2[pos2] -'0') + carry - '0';
            carry = (sum/10) ? '1' : '0';
            ans += ('0' + sum % 10);
            --pos1; --pos2;
        }
        // calulating the sum of the rest digits in the longer string and the carry
        while(pos1 >= 0){
            int sum = (num1[pos1] - '0') + carry - '0';
            carry = (sum/10) ? '1' : '0';
            ans += ('0' + sum % 10);
            --pos1;
        }
        while(pos2 >= 0){
            int sum = (num2[pos2] - '0') + carry - '0';
            carry = (sum/10) ? '1' : '0';
            ans += ('0' + sum % 10);
            --pos2;
        }
        if(carry == '1') ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
