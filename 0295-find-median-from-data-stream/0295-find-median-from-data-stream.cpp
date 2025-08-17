class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> min_heap;
    priority_queue<int> max_heap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        min_heap.push(num);
        if (min_heap.size() - max_heap.size() > 1) {
            int val = min_heap.top();
            min_heap.pop();
            max_heap.push(val);
        }

        if (!min_heap.empty() && !max_heap.empty() && min_heap.top() < max_heap.top()) {
            int min_tmp = min_heap.top();
            int max_tmp = max_heap.top();
            min_heap.pop();
            max_heap.pop();
            min_heap.push(max_tmp);
            max_heap.push(min_tmp);
        }
    }
    
    double findMedian() {
        int total_n = min_heap.size() + max_heap.size();
        if (total_n == 0) return -1;

        if (total_n % 2 == 0) {
            return (min_heap.top() + max_heap.top()) / 2.0;
        } else {
            return min_heap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */