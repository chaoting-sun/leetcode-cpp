class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
            if (dq.empty() || nums[dq.back()] > nums[i]) dq.push_back(i);

            while (i - dq.front() + 1 > k) dq.pop_front();
            if (i >= k - 1) ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};

// nums=[1,3,1,2,0,5], k=3
// 0 q=[(1,0)]
// 1 q=[(3,1)]
// 2 q=[(3,1),(1,2)] -> 3
// 3 q=[(3,1),(2,3)] -> 3
// 4 q=[(3,1),(2,3),(0,4)] -> 3
