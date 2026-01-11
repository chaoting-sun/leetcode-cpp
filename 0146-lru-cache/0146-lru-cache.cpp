class LRUCache {
private:
    list<pair<int,int>> lst; // value
    unordered_map<int, list<pair<int,int>>::iterator> mp; // key, iterator of value in lst
    int capacity;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        auto it = mp.find(key);
        if (it == mp.end()) return -1;
        
        int value = (*(it->second)).second;
        lst.erase(it->second);

        lst.push_back({ key, value });
        mp[key] = prev(lst.end());
        
        return value;
    }
    
    void put(int key, int value) {
        auto it = mp.find(key);
        if (it != mp.end()) {
            lst.erase(it->second);
        }
        
        lst.push_back({ key, value });
        mp[key] = prev(lst.end());
        
        if (lst.size() > capacity) {
            int deleted_key = (*lst.begin()).first;
            mp.erase(deleted_key);
            lst.erase(lst.begin());
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


// { key1: val1, key2: val2, ... }

// key1 -> key2 -> key3 ...

// get
// key1 -> key2 -> key3 ... -> keyn
// key1 -> key3 ... -> keyn -> key2

// put
// key1 -> key2 -> key3 ... -> keyn
// key1 -> key2 -> key3 ... -> keyn -> key(n+1)