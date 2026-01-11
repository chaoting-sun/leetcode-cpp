class LFUCache {
private:
    struct Node {
        int key;
        int value;
        int freq;
    };

    unordered_map<int, list<Node>> freqToList;
    unordered_map<int, list<Node>::iterator> keyToIter;
    int min_freq = 0;
    int capacity;

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        auto it = keyToIter.find(key);
        if (it == keyToIter.end()) return -1;

        int freq = it->second->freq;
        it->second->freq++;
        
        if (!freqToList.count(freq + 1)) {
            freqToList[freq + 1] = {};
        }
        freqToList[freq + 1].splice(freqToList[freq + 1].end(), freqToList[freq], it->second);

        if (min_freq == freq && freqToList[freq].empty()) {
            min_freq++;
        }
        return it->second->value;
    }
    
    void put(int key, int value) {
        auto it = keyToIter.find(key);

        // update
        if (it != keyToIter.end()) {
            int freq = it->second->freq;
            it->second->freq++;
            it->second->value = value;
            freqToList[freq + 1].splice(freqToList[freq + 1].end(), freqToList[freq], it->second);
            if (freq == min_freq && freqToList[freq].size() == 0) min_freq++;
            return;
        }

        // add
        if (keyToIter.size() == capacity) {
            int key_to_delete = freqToList[min_freq].front().key;
            keyToIter.erase(key_to_delete);
            freqToList[min_freq].erase(freqToList[min_freq].begin());
        }

        min_freq = 1;
        freqToList[1].push_back({ key, value, 1 });
        keyToIter[key] = prev(freqToList[1].end());
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// useCounter: { key: count }
// keyToIter: { key: iterator in cacheList }
// cacheList: [{ key, value }, ...]

// get
// - update useCounter
// - move element in cacheList to the end

// put
// - 
