class Solution {
  /*
   * Complexity: O(nlgn)
   * Space: O(n)
   */
public:
    string frequencySort(string s) {
        string ans = "";
        unordered_map<char, int>occurrence;
        
        for(char& c : s){
            occurrence[c] += 1;
        }
        
        vector<pair<char,int>>occur_vec(occurrence.begin(), occurrence.end());
        sort(occur_vec.begin(), occur_vec.end(), [](const pair<char, int>& a, const pair<char, int>& b){
           return a.second > b.second; 
        });
        
        for(auto& it : occur_vec){
            for(int i = 0; i < it.second; ++i){
                ans += it.first;
            }
        }
        
        return ans;
    }
};
