class Solution {
/*
 * You can use vector<int>(256,0) to replace the hashmap when the key is char.
 */
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int>hash;
        for(int i = 0; i < s.length(); ++i){
            auto it = hash.find(s[i]);
            if(it != hash.end()){
                it -> second += 1;
            }
            else{
                hash.insert({s[i], 1});
            }
        }
        for(int i = 0; i < t.length(); ++i){
            auto it = hash.find(t[i]);
            if(it != hash.end()){
                it -> second -= 1;
            }
            else return false;
        }
        auto it = hash.begin();
        while(it != hash.end()){
            if(it -> second != 0) return false;
            ++it;
        }
        return true;
    }
};
