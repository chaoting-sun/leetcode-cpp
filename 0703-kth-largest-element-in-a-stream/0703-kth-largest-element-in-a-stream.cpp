class KthLargest {
public:
    // Approach: Heap
    // Time: O((m+n)logn). n is length of nums, m is the number of time calling add
    // - initialization: n*logk
    // - add: m*logk
    // Space: O(k)

    int k;
    priority_queue<int, vector<int>, greater<int>> min_pq;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int val: nums) add(val);
    }
    
    int add(int val) {
        min_pq.push(val);
        while (min_pq.size() > k) {
            min_pq.pop();
        }
        return min_pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */