class Solution {
  /*
   * Complexity: O(max(len(a), len(b)))
   * Space: O(1)
   */
public:
    string addBinary(string a, string b) {
        int a_l = a.length();
        int b_l = b.length();
        int carry = 0;
        string ans;
        for(int i = 0; i < max(a_l, b_l); ++i){
            int d_a = (a_l - 1 - i >= 0 ? a[a_l -1 -i] - '0': 0);
            int d_b = (b_l - 1 - i >= 0 ? b[b_l- 1- i] - '0': 0);
            int sum = d_a + d_b + carry;
            carry = sum / 2;
            sum = sum % 2;
            ans += (char)(sum + '0');
        }
        if(carry) ans += (char)(carry + '0');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
