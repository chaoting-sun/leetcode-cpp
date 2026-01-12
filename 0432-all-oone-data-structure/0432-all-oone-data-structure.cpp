class AllOne {
private:
    struct Node {
        int count;
        unordered_set<string> keys;
    };

    list<Node> lst;
    unordered_map<string, list<Node>::iterator> keyToIter;

public:
    AllOne() {
        
    }
    
    void inc(string key) {
        auto it = keyToIter.find(key);
        // key does not exist
        if (it == keyToIter.end()) {
            // lst: 1. [], 2. [{ count: 2, keys: { ... } }, ...]
            if (lst.empty() || lst.begin()->count != 1) {
                lst.insert(lst.begin(), { 1, { } });
            }
            lst.begin()->keys.insert(key); // add new source
            keyToIter[key] = lst.begin(); // add its reference
            return;
        }

        // key exists
        auto curr_iter = it->second;
        auto next_iter = next(it->second, 1);

        curr_iter->keys.erase(key);

        if (next_iter == lst.end() || next_iter->count > curr_iter->count + 1) {
            lst.insert(next_iter, { curr_iter->count + 1, {} });
            next_iter = next(curr_iter, 1); // insert new element if it doesn't exist
        }
        next_iter->keys.insert(key); // add new source
        keyToIter[key] = next_iter; // add its reference

        if (curr_iter->keys.empty()) lst.erase(curr_iter);
    }
    
    void dec(string key) {
        auto it = keyToIter.find(key);
        if (it == keyToIter.end()) return;

        auto curr_iter = it->second;
        curr_iter->keys.erase(key);

        if (curr_iter->count == 1) {
            keyToIter.erase(key); // delete reference
            if (curr_iter->keys.empty()) lst.erase(curr_iter); // delete source
            return;
        }
        
        auto prev_iter = lst.end();
        if (curr_iter != lst.begin()) prev_iter = prev(curr_iter, 1);

        if (curr_iter == lst.begin() || prev_iter->count + 1 < curr_iter->count) {
            lst.insert(curr_iter, { curr_iter->count - 1, {} });
            prev_iter = prev(curr_iter, 1);
        }
        prev_iter->keys.insert(key); // add the source in prev iterator
        keyToIter[key] = prev_iter;

        if (curr_iter->keys.empty()) lst.erase(curr_iter); // remove the old source if it is empty 
        
    }
    
    string getMaxKey() {
        if (lst.empty()) return "";
        return *(lst.back().keys.begin());
    }
    
    string getMinKey() {
        if (lst.empty()) return "";
        return *(lst.front().keys.begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */

//  min_count
//  max_count
//  { count: { key } }