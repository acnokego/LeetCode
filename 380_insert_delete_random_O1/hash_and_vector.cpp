class RandomizedSet {
private:
    // store the value can be accessed by random()
    vector<int> nums;
    // store the value and its index in nums
    unordered_map<int, int> table;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        auto it = table.find(val);
        if(it != table.end()) return false;
        else{
            table[val] = nums.size();
            nums.push_back(val);
            return true;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto it = table.find(val);
        if(it != table.end()){
            // overwrite the removed element using the last element
            nums[it -> second] = nums.back();
            table[nums.back()] = it -> second;
            // pop the back
            nums.pop_back(); 
            table.erase(it);
            return true;
        }
        else return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % nums.size()];     
    }
};
