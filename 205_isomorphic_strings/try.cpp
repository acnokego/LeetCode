class Solution {
  /*
   *  Complexity: O(n)
   *  Space: O(n)
   */
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, vector<int>>index_s;
        unordered_map<char, vector<int>>index_t;
        for(int i = 0; i < s.length(); ++i){
            index_s[s[i]].push_back(i);
            index_t[t[i]].push_back(i);
        }
        vector<bool>check(s.length(), 0);
        for(int i = 0; i < s.length(); ++i){
            if(!check[i]){
                // check if the correspond character's number of occurrences are the same
                if(index_s[s[i]].size() != index_t[t[i]].size()) return false;
                for(int j = 0; j < index_s[s[i]].size(); ++j){
                // check the occurred index is the same
                    int id_s = index_s[s[i]][j];
                    int id_t = index_t[t[i]][j];
                    if(id_s != id_t) return false;
                    check[id_s] = 1;
                }
                
            }
        }
        return true;
    }
};
