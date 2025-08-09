class LRUCache {
public:
    int cap;
    list<int> dllist; // key
    unordered_map<int, list<int>::iterator> key2iter; // key -> interator
    unordered_map<int, int> key2val;

    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (key2iter.find(key) == key2iter.end()) return -1;
        
        auto it = key2iter[key];
        dllist.erase(it);
        dllist.push_back(key);
        key2iter[key] = prev(dllist.end());
        return key2val[key];
    }
    
    void put(int key, int value) {
        // remove the old one if exists
        if (key2iter.find(key) != key2iter.end()) {
            dllist.erase(key2iter[key]);
            key2iter.erase(key);
        }

        // add the new in the back
        dllist.push_back(key);
        key2iter[key] = prev(dllist.end());
        key2val[key] = value;

        // remove the oldest if the amount > capacity
        if (dllist.size() > cap) {
            int old_key = dllist.front();
            auto old_it = key2iter[old_key];
            dllist.erase(old_it);
            key2iter.erase(old_key);
            key2val.erase(old_key);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
