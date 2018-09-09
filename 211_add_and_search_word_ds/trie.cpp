class TrieNode {
public:
    bool isWord;
    vector<TrieNode*>children; // 26 character
    TrieNode(): isWord(false){
        children = vector<TrieNode*>(26, NULL);
    }
};

class WordDictionary {
private:
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    WordDictionary(){
        root = new TrieNode();
    }
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* curr = root;
        for(auto & c : word){
            if(!curr -> children[c - 'a']){
                curr -> children[c - 'a'] = new TrieNode(); 
            }
            curr = curr -> children[c - 'a'];
        }
        curr -> isWord = true;  
    }
    bool query(string& word, int pos, TrieNode* start){
        TrieNode* curr = start;
        for(int i = pos; i < word.length(); ++i){
            // directly check if child exist
            if(word[i] != '.'){
                if(!curr -> children[word[i] - 'a']) return false;
                curr = curr -> children[word[i] - 'a'];
            }
            // check each possible children
            else if(word[i] == '.'){
                // for each possible children, check if word[i+1 : end] exist 
                for(int j = 0; j < 26; ++j){
                    if(curr -> children[j]){
                        if(query(word, i+1, curr -> children[j])) return true;
                    }
                }
                // cannot be found after dfs
                return false;
            }
        }
        return curr -> isWord;
    }
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return query(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
