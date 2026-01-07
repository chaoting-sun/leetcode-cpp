class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return;

        k %= n;

        vector<int> result(n);
        for (int i = 0; i < k; i++) {
            result[i] = nums[n - k + i];
        }
        for (int i = k; i < n; i++) {
            result[i] = nums[i - k];
        }
        for (int i = 0; i < n; i++) {
            nums[i] = result[i];
        }
    }
};

// 1 2 3, k = 4
// k %= 4 -> k = 1
// result = [3, 1, 2]
// result[1] = nums[0] = 1
// result[2] = nums[1] = 2