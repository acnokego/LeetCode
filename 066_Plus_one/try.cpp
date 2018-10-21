class Solution {
  /*
   * Complexity : O(n)
   * Space: O(n)
   */
public:
    vector<int> plusOne(vector<int>& digits) {
        int l = digits.size();
        vector<int>ans;
        if(l == 0) return ans;
        
        int carry = 0;
        int add_one = 0;
        for(int i = l - 1; i >=0; --i) {
            if(i == l-1) add_one = 1;
            else add_one = 0;
            int sum = digits[i] + carry + add_one;
            carry = sum / 10;
            sum = sum % 10;
            ans.push_back(sum);
        }
        if(carry) ans.push_back(carry);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
