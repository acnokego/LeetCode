class Solution {
  /*
   * Complexity: O(max(n^2, n*L)) L: the longest length
   * Space: O(n)
   */
public:
    int maxProduct(vector<string>& words) {
        int max_ans = 0;
        vector<int>occur(words.size(), 0);
        for(int i = 0; i < words.size(); ++i){
            for(auto & c : words[i]){
                occur[i] |= (1 << (c - 'a'));
            }
        }
        for(int i = 0; i < words.size(); ++i){
            for(int j = i + 1; j < words.size(); ++j){
                if((occur[i] & occur[j]) == 0){
                    int product = words[i].length() * words[j].length();
                    max_ans = (max_ans > product) ? max_ans : product;
                }
            }
        }
        return max_ans;
    }
};
