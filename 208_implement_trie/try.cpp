class Trie {
private:
    unordered_set<string>hash;
public:
    /** Initialize your data structure here. */
    Trie() {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        hash.insert(word);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto it = hash.find(word);
        return (it != hash.end());
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        for(auto& s : hash){
            if(s.length() >= prefix.length()){
                if(s.substr(0, prefix.length()) == prefix) return true;
            }
        }
        return false;
    }
};

