class Solution {
  /*
   * Complexity: O(n^2)
   * Space: O(1)
   */
public:
    int countNumbersWithUniqueDigits(int n) {
        int ans = 0;

        // find number of permutations of different length
        for(int i = n; i >= 1 ; --i){
            int factor = 9;
            int temp = 9;
            
            // for permutations of i digits
            for(int j = i - 1; j >= 1; --j){
                temp *= factor;
                --factor;
            }
            ans += temp;
        }
        return ans + 1; // for 0
        
    }
};
