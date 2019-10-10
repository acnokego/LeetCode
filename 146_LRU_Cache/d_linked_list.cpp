class LRUCache {
private:
    struct LRUNode {
        LRUNode* prev;
        LRUNode* next;
        int key;
        int value;
    };
    LRUNode* lru;
    unordered_map<int, LRUNode*>map;
    int cap;
public:
    LRUCache(int capacity) {
        lru = NULL;
        cap = capacity;
    }
    // O(1)
    int get(int key) {
        // move the node to the tail of LRU
        if(map.count(key)){
            LRUNode *node = map[key];
            // connect the nodse before key and after the key.
            if(node == lru){
                lru = lru -> next;
                node -> next = node;
                node -> prev -> next = node;
            } else {
                node -> next -> prev = node -> prev;
                node -> prev -> next = node -> next;
                lru -> prev -> next = node; // move to the end
                node -> prev = (lru -> prev == node) ? node -> prev : lru -> prev;
                node -> next = node;
                lru -> prev = node;
            }
            return node -> value;
        } else {
            return -1;
        }
    }
    // O(1)
    void put(int key, int value) {
        if(!map.count(key)){
            LRUNode *new_node = new LRUNode;
            new_node -> key = key;
            new_node -> value = value;
            new_node -> prev = new_node;
            new_node -> next = new_node;
            if(map.size() == cap){
                map.erase(lru -> key); // remove the head
                // check if there is only one node in the cache now
                if(lru -> prev == lru){
                    lru = new_node;
                } else{
                    new_node -> prev = lru -> prev;
                    new_node -> prev -> next = new_node; // new node add to the end
                    lru = lru -> next;
                    lru -> prev = new_node; // the head point to the end
                }
            } else {
                if(lru != NULL){
                    new_node -> prev = lru -> prev;
                    new_node -> prev -> next = new_node; // new node add to the end
                    lru -> prev = new_node;
                } else {
                    lru = new_node;
                }
            }
            map[key] = new_node;
        } else {
            LRUNode *node = map[key];
            node -> value = value;
            // update LRU, move the node to the end
            if(node == lru){ // node is the head
                lru = node -> next; 
                node -> next = node;
                node -> prev -> next = node;
            } else {
                // connect the nodes before key and after the key.
                node -> next -> prev = node -> prev; 
                node -> prev -> next = node -> next;
                lru -> prev -> next = node; // add to the end
                node -> prev = (lru -> prev == node) ? node -> prev : lru -> prev;
                node -> next = node;
                lru -> prev = node;
            } 
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
