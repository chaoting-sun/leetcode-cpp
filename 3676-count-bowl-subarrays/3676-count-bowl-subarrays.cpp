// Approach: Monotonic Stack (Nearest Greater Elements)
//
// A subarray nums[l..r] is a bowl iff
//   min(nums[l], nums[r]) > max(nums[l+1..r-1])  and  r - l + 1 >= 3.
//
// Key observation (distinct values):
// Each bowl corresponds to the side with the smaller endpoint s.
// Looking from s toward the other side, the FIRST strictly greater element
// must be exactly the opposite endpoint. Otherwise some greater element appears
// inside and breaks the bowl condition.
//
// Therefore we can count bowls via nearest greater elements (NGE):
// - If the smaller endpoint is on the LEFT: NGR[s] = r and (r - s) >= 2.
// - If the smaller endpoint is on the RIGHT: NGL[s] = l and (s - l) >= 2.
// Because values are distinct, the smaller endpoint is unique ⇒ no double-count.
//
// How to compute NGE in O(n) with a decreasing stack:
// - NGR (next greater to the right):
//     scan i = 0..n-1, while stack not empty and nums[stk.top] < nums[i],
//     set NGR[stk.top] = i and pop; then push i.
// - NGL (next greater to the left):
//     scan i = n-1..0, while stack not empty and nums[i] > nums[stk.top],
//     set NGL[stk.top] = i and pop; then push i.
//
// Finally, count bowls from NGR and NGL with the length check (gap >= 2).
// Time: O(n); Space: O(n).

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