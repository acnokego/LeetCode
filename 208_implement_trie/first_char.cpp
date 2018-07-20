class Trie {
private:
    unordered_set<string>hash;
    // map the string's first character
    unordered_map<char, vector<string> >hash_map;
public:
    /** Initialize your data structure here. */
    Trie() {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        hash.insert(word);
        hash_map[word[0]].push_back(word);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto it = hash.find(word);
        return (it != hash.end());
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        // only check the vector that has key mapped to the first character of
        // prefix.
        for(auto& s : hash_map[prefix[0]]){
            if(s.length() >= prefix.length()){
                if(s.substr(0, prefix.length()) == prefix) return true;
            }
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
