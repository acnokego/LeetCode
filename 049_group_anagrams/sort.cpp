class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > map;
        for(auto str : strs){
            string cpy = str;
            sort(str.begin(), str.end());
            map[str].push_back(cpy);
        }
        vector< vector<string> > ans;
        for(auto it : map){
            ans.push_back(it.second);
        }
        return ans;
    }
};
