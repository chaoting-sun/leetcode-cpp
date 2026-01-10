// nlogk ~ nlogn
// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         int n = nums.size();
//         if (n < k) return {};

//         priority_queue<pair<int,int>> max_heap;
//         vector<int> result;

//         for (int i = 0; i < n; i++) {
//             max_heap.push({ nums[i], i });
//             if (i < k - 1) continue;

//             // [i - k + 1, i]
//             while (max_heap.top().second <= i - k) {
//                 max_heap.pop();
//             }
//             max_heap.push({ nums[i], i });
//             result.push_back(max_heap.top().first);
//         }

//         return result;
//     }
// };

// monotonic queue; strictly decreasing
// [大 -> 小]
// 最長：k

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < k || k == 0) return {};

        deque<int> dq;
        vector<int> result;

        for (int i = 0; i < n; i++) {
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            // [i - k + 1, i]
            while (i - dq.front() + 1 > k) {
                dq.pop_front();
            }

            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};

// nums = [1, 3, 1, 2], k = 2
// dq = [0]
// for loop: i = 1 2 3
// i = 1
//  dq = [], dq = [1]
//  result = [3]
// i = 2
//  dq = [1, 2]
//  result = [3, 3]
// i = 3
//  dq = [1]
//  dq = [1, 3]
//  dq = [3]
//  result = [3,3,2]

