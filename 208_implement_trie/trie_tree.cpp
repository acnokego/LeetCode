/*
 * All operations are O(n) the length of the input word.
 * The method is referred to 
 * https://leetcode.com/problems/implement-trie-prefix-tree/discuss/58852/C++-My-solution-easy-to-understand:)
 */

class TrieNode {
public:
    char content;
    bool isEnd;
    int shared; // for delete
    vector<TrieNode*> children;
    TrieNode():content(' '), isEnd(false), shared(0){};
    TrieNode(char c): content(c), isEnd(false), shared(0){};
    TrieNode* search_child(char c){
        for(auto child: children){
            if(child -> content == c) return child;
        }
        return NULL;
    }
    ~TrieNode(){
        // would call destructor recursively
        for(auto child: children) delete child;
    }
    
};

class Trie {
private:
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        if(search(word)) return;
        TrieNode* curr = root;
        for(auto c : word){
            TrieNode* child = curr -> search_child(c);
            if(child != NULL){
                curr = child;
            }
            else{
                TrieNode* newNode = new TrieNode(c);
                curr -> children.push_back(newNode);
                curr = newNode;
            }
            ++curr->shared;
        }
        curr -> isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* curr = root;
        for(auto c : word){
            TrieNode* child = curr -> search_child(c);
            if(child == NULL) return false;
            curr = child;
        }
        return curr -> isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(auto c : prefix){
            TrieNode* child = curr -> search_child(c);
            if(child == NULL) return false;
            curr = child;
        }
        return true;
    }
    ~Trie(){
        delete root;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
