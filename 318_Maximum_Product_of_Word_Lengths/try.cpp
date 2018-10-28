class Solution {
  /* TLE!!!
   * Complexity: O(n^2 * L)
   * Space: O(1)
   */
public:
    struct cmp{
      bool operator()(string s1, string s2){
          return s1.length() > s2.length();
      }  
    };
    bool contain_letters(string s1, string s2){
        unordered_set<char>occur(s2.begin(), s2.end());
        for(auto & c : s1){
            if(occur.count(c)) return true;
        }
        return false;
    }
    int maxProduct(vector<string>& words) {
        // sort the string from longer length to shorter length
        //sort(words.begin(), words.end(), cmp());
        int max_ans = 0;
        for(int i = 0; i < words.size(); ++i){
            for(int j = i + 1; j < words.size(); ++j){
                int product = words[i].length() * words[j].length();
                if(product > max_ans && !contain_letters(words[i], words[j])){
                    max_ans = product;
                }
            }
        }
        return max_ans;
    }
};
