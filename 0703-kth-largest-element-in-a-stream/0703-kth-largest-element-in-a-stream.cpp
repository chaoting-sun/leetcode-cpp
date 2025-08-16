class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<int>> min_pq;
    priority_queue<int> max_pq;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        int n = nums.size();
        for (int val: nums) min_pq.push(val);
        for (int i = 0; i < max(0, n - k); i++) {
            int val = min_pq.top();
            min_pq.pop();
            max_pq.push(val);
        }
    }
    
    int add(int val) {
        min_pq.push(val);
        while (min_pq.size() > k) {
            int smallest = min_pq.top();        
            min_pq.pop();
            max_pq.push(smallest);
        }

        return min_pq.top();
    }

    // add -3 -> min_pq = [-3], max_pq = [] -> -3
    // add -2 -> min_pq = [-2], max_pq = [-3] -> -2
    // add -4 -> min_pq = [-2], max_pq = [-3,-4] -> -2
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */