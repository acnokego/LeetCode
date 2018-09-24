class Solution {
  /*
   * Complexity: O(n^2)
   * Space: O(n)
   */
public:
    int maximumSwap(int num) {
        string num_s = to_string(num);
        int len = num_s.length();
        int swap_num = num;
        for(int i = 0; i < len; ++i){
            for(int j = i + 1; j < len; ++j){
                swap(num_s[i], num_s[j]);
                swap_num = max(swap_num, stoi(num_s));
                swap(num_s[i], num_s[j]);
            }
        }
        return swap_num;
    }
};
