class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> min_heap;
    priority_queue<int> max_heap;

    MedianFinder() {
        
    }
    
    // Time: O(logn)
    void addNum(int num) {
        min_heap.push(num);
        
        // two cases: size = (n + 1, n) or (n, n)

        max_heap.push(min_heap.top());
        min_heap.pop();

        if (min_heap.size() < max_heap.size()) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
    }
    
    // Time: O(1)
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