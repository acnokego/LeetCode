class LRUCache {
private:
    struct LRUNode {
        LRUNode* prev;
        LRUNode* next;
        int key;
        int value;
        LRUNode(LRUNode* p, LRUNode* n, int k, int v):prev(p),next(n), key(k), value(v){};
    };
    LRUNode* head;
    LRUNode* tail;
    unordered_map<int, LRUNode*>map;
    int cap;
public:
    LRUCache(int capacity) {
        head = new LRUNode(NULL, NULL, -1, -1);
        tail = new LRUNode(NULL, NULL, -1, -1);
        head -> next = tail;
        tail -> prev = head;
        cap = capacity;
    }
    void remove_node(LRUNode* node){
        LRUNode* prev_node = node -> prev;
        LRUNode* next_node = node -> next;
        prev_node -> next = next_node;
        next_node -> prev = prev_node;
    }
    void append_tail(LRUNode* node){
        LRUNode* origin_tail = tail -> prev;
        tail -> prev = node;
        node -> next = tail;
        node -> prev = origin_tail;
        origin_tail -> next = node;
    }
    int get(int key) {
        // move the node to the tail of LRU
        if(map.count(key)){
            LRUNode *node = map[key];
            // connect the node before key and after the key.
            remove_node(node);
            append_tail(node);
            return node -> value;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(!map.count(key)){
            LRUNode *new_node = new LRUNode(NULL, NULL, key, value);
            if(map.size() == cap && cap != 0){
                // pop the LRU node and put the new to the end
                map.erase(head->next->key);
                remove_node(head -> next);
                append_tail(new_node);
            } else {
                // new node, put it to the end
                append_tail(new_node);
            }
            map[key] = new_node;
        } else {
            LRUNode *node = map[key];
            node -> value = value;
            // pop the node and put it to the end
            remove_node(node);
            append_tail(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
