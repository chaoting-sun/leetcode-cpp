class HitCounter {
private:
    queue<int> hits;
public:

    HitCounter() {
    }
    
    void hit(int timestamp) {
        this->hits.push(timestamp);
    }
    
    int getHits(int timestamp) {
        int minTimeStamp = timestamp - 300 + 1;
        while (!this->hits.empty() && this->hits.front() < minTimeStamp) {
            this->hits.pop();
        }
        return this->hits.size();
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */