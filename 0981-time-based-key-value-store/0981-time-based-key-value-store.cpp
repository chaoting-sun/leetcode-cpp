class TimeMap {
public:
    // Approach1: Hash map.
    // Time: suppose that set() is called M times, get() is called N times, and the average length of key and value strings is L
    // - set():
    //   - Hashing string key takes O(L)
    //   - Copy the string value takes O(L)
    //   - Total Time = O(2L * M) = O(ML)
    // - get():
    //   - searching the value given key and timestamp in the timeMap[key] takes O(L).
    //   - Total Time = O(NL)

    // unordered_map<string, unordered_map<int, string>> timeMap;
    // TimeMap() {
    // }
    
    // void set(string key, string value, int timestamp) {
    //     timeMap[key][timestamp] = value;
    // }
    
    // string get(string key, int timestamp) {
    //     if (!timeMap.count(key)) {
    //         return "";
    //     }
    //     int max_time = -1;
    //     for (auto record: timeMap[key]) {
    //         if (record.first <= timestamp && record.first > max_time) {
    //             max_time = record.first;
    //         }
    //     }
    //     return max_time == -1 ? "" : timeMap[key][max_time];
    // }

    // Approach2: sorted map + binary search
    // Time: suppose that set() is called M times, get() is called N times, and the average length of key and value strings is L
    // - set:
    //     - the map is a red black tree (a binary search tree) that every insertion takes O(log(n)) in worst case where n is
    //       the number of nodes. also, comparing each string needs O(L) time. So one set() needs O(log(M)*L) in worst case.
    //     - time: O(M*(log(M)*L))
    // - get:
    //     - O(L*logM) for one get()
    //     - time: O(N*(L*logM))
    // Space:
    // - set: O(M*L) in total
    // - get: O(1)

    // unordered_map<string, map<int, string>> timeMap;
    // TimeMap() {
    // }
    
    // void set(string key, string value, int timestamp) {
    //     timeMap[key][timestamp] = value;
    // }
    
    // string get(string key, int timestamp) {
    //     auto it = timeMap[key].upper_bound(timestamp);
    //     if (it == timeMap[key].begin()) {
    //         return "";
    //     }
    //     return prev(it)->second;
    // }

    // Approach3: Array + Binary Search. We can use array as "all the timestamps of set are strictly increasing"
    // Time: suppose that set() is called M times, get() is called N times, and the average length of key and value strings is L
    // - set(): O(1) -> total: O(M)
    // - get(): we use binary search (logM), and each comparison needs O(L), so in total it's O(N*(L*logM))
    // Space:
    // - set(): O(ML)
    // - get(): O(1)

    unordered_map<string, vector<pair<int, string>>> timeMap;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        timeMap[key].push_back({ timestamp, value });
    }
    
    string get(string key, int timestamp) {
        if (!timeMap.count(key)) return "";
        
        int n = timeMap[key].size();
        int left = 0, right = n;

        // find the first value that is larger than (>) timestamp
        // we can also use upper_bound(timestamp), which find the first value in the vector that is larger than the timestamp
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (timeMap[key][mid].first <= timestamp) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        // timeMap[key][right] is the first value larger than timestamp, so to find the last value not larger than timeMap[key][right]:
        // if right is 0, than no one <= timestamp
        // if right is not 0, than timeMap[key][right-1] is the last value <= timestamp

        if (right == 0) return "";
        return timeMap[key][right - 1].second;
    }  
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */