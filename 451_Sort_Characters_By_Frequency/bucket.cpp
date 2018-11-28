class Solution {
  /*
   * Complexity: O(n)
   * Space: O(n)
   */
public:
    string frequencySort(string s) {
        string ans = "";
        unordered_map<char, int>occurrence;
        vector<string>bucket(s.length()+1, "");
        
        for(char& c : s){
            occurrence[c] += 1;
        }
        
        for(auto& it : occurrence){
            bucket[it.second].append(it.second, it.first);
        }
        
        for(int i = s.length(); i >= 1; --i){
            if(!bucket[i].empty()){
                ans += bucket[i];
            }
        }
        
        return ans;
    }
};
