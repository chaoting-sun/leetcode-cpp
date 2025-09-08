class Solution {
public:    
    long long bowlSubarrays(vector<int>& nums) {
        int n = nums.size();
        stack<int> stk;
        vector<int> NGR(n, n); // next greater to the right
        vector<int> NGL(n, -1); // next greater to the left

        for (int i = 0; i < n; i++) {
            while (!stk.empty() && nums[stk.top()] < nums[i]) {
                NGR[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }

        while (!stk.empty()) stk.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && nums[i] > nums[stk.top()]) {
                NGL[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }

        long long cnt = 0;
        for (int i = 0; i < n; i++) {
            if (NGR[i] != n && NGR[i] - i >= 2) cnt++;
        }
        for (int i = 0; i < n; i++) {
            if (NGL[i] != -1 && i - NGL[i] >= 2) cnt++;
        }
        return cnt;
    }
};

// [2,5,3,1,4]
// i=0, stk = [0]
// i=1, stk = [], NGR = [1,5,5,5,5], stk = [1]
// i=2, stk = [1,2]
// i=3, stk = [1,2,3]
// i=4, stk = [1,2], NGR = [1,5,5,4,5], stk = [1], NGR = [1,5,4,4,5], stk = [1,4]

// ideal:
// NGR = [1,5,4,4,5] -> 1
// NGL = [-1,-1,1,2,1] -> 1