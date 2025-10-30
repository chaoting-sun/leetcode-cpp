class HitCounter {
public:
    vector<int> hits;

    HitCounter() {
        
    }
    
    void hit(int timestamp) {
        hits.push_back(timestamp);
    }
    
    int getHits(int timestamp) {
        if (hits.empty()) return 0;

        int target = timestamp - 300 + 1;
        if (target < 0) return hits.size();
        
        // find 1st number >= timestamp - 300
        int left = -1, right = hits.size();
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (hits[mid] >= target) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return hits.size() - right;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */