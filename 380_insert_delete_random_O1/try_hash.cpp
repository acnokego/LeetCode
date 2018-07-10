class RandomizedSet {
private:
    unordered_map<int, bool> table;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        auto it = table.find(val);
        if(it != table.end()) return false;
        else{
            ++table[val];
            return true;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto it = table.find(val);
        if(it != table.end()){
            table.erase(it);
            return true;
        }
        else return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int n = table.size();
        int rand_idx = rand() % n;
        auto it = table.begin();
        for(int i = 0; i < rand_idx; ++i) ++it;
        return it -> first;      
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
