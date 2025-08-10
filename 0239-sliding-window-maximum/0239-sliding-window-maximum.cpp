class Solution {
public:
    // Approach1: Monotonic Deque.
    // We can maintain a deque as the sliding window in a way such that we can get the maximum value in O(1).
    // To achieve this, the deque should be monotonic. also, the values inside should be decreasing such that
    // we can track if the window size is not larger than k.
    // Therefore, we loop nums and push the element into the deque. Before pushing, we pop out all the values
    // that is not larger than the current value to maintain the monotonic decreasing property. We store the
    // index into the deque, so before we check the maximum value in deque's front, we can compute if the current
    // deque contain window that is larger than k.

    // Time: O(n)
    // Space: O(k)

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
            dq.push_back(i);

            while (i - dq.front() + 1 > k) dq.pop_front();
            if (i >= k - 1) ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};