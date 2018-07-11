class Solution {
public:
    int firstUniqChar(string s) {
        vector<int>hash(256);
        for(auto c: s){
            ++hash[int(c)];
        }
        int l = s.length();
        for(int i = 0; i < l; ++i){
            if(hash[int(s[i])] == 1) return i;
        }
        return -1;
    }
};
