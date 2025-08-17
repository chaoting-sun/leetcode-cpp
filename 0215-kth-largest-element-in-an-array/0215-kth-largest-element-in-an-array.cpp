class Solution {
public:
    // Intuition: we need to get the k th largest element without sorting,
    // so we need a data structure that enable us to know if an element is
    // smaller than or larger than another one -> heap
    // Approach: Min Heap
    // Time: O(n*logk)
    // Space: O(k)

    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int val: nums) {
            pq.push(val);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
};