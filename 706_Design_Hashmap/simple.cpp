class HashNode {
    private:
        HashNode* next;
        int value;
        int key;
    public: 
        HashNode(int k, int v):key(k), value(v), next(NULL){};
        HashNode* get_next(){
            return next;
        }
        void set_next(HashNode* ptr){
            next = ptr;
        }
        int get_key(){
            return key;
        }
        void set_key(int k){
            key = k;
        }
        int get_value(){
            return value;
        }
        void set_value(int v){
            value = v;
        }    
};
class MyHashMap {
public:

    vector<HashNode*>table;
    int tabel_size;
    hash<int>hash_func;
    /** Initialize your data structure here. */
    MyHashMap() {
        tabel_size = 10000;
        table = vector<HashNode*>(10000);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int bucket = hash_func(key) % tabel_size;
        if(table[bucket] == NULL){
            HashNode* new_node = new HashNode(key, value);
            table[bucket] = new_node;
        } else{
            HashNode* curr = table[bucket];
            HashNode* prev = NULL;
            // search for the key
            while(curr){
                if(curr -> get_key() == key){
                    curr -> set_value(value);
                    return;
                } else{
                    prev = curr;
                    curr = curr -> get_next();
                }
            }
            // push the new node in the end of list
            HashNode* new_node = new HashNode(key, value);
            prev -> set_next(new_node);
            return;
        }
        
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int bucket = hash_func(key) % tabel_size;
        HashNode* curr = table[bucket];
        if(!curr) return -1;
        // search for the key
        while(curr){
            if(curr -> get_key() == key){
                return curr -> get_value();
            } else{
                curr = curr -> get_next();
            }
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int bucket = hash_func(key) % tabel_size;
        HashNode* curr = table[bucket];
        HashNode* prev = NULL;
        if(!curr) return;
        // search for the key
        while(curr){
            if(curr -> get_key() == key){
                if(prev){
                    prev -> set_next(curr -> get_next());  
                }else {
                    table[bucket] = curr -> get_next();
                }
                return;
            } else{
                prev = curr;
                curr = curr -> get_next();
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
