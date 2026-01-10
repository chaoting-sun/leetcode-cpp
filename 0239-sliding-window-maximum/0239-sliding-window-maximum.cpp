class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < k) return {};

        priority_queue<pair<int,int>> max_heap;
        vector<int> result;

        for (int i = 0; i < n; i++) {
            max_heap.push({ nums[i], i });
            if (i < k - 1) continue;

            // [i - k + 1, i]
            while (max_heap.top().second <= i - k) {
                max_heap.pop();
            }
            max_heap.push({ nums[i], i });
            result.push_back(max_heap.top().first);
        }

        return result;
    }
};

// max heap (k) -> (val, idx)

// 1   3   4   5   7
// [       ]

// 1. if the element is in the window -> pop
// 2. add new element
// 3. get the max value on the top