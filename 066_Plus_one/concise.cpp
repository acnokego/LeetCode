class Solution {
  /*
   * Complexity: O(n) the worst case
   * Space: O(1)
   */
public:
    vector<int> plusOne(vector<int>& digits) {
        int l = digits.size();
        if(l == 0) return vector<int>();
        
        for(int i = l - 1; i >=0; --i) {
            if(digits[i] == 9){
                digits[i] = 0;
            }
            else{
                ++digits[i];
                return digits;
            }  
        }
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
};
