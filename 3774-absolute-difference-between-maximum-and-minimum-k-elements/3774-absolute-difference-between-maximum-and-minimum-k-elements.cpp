// class Solution {
// public:
//     int absDifference(vector<int>& nums, int k) {
//         int n = nums.size();
//         sort(nums.begin(), nums.end());
//         int max_sum = 0, min_sum = 0;
//         for (int i = 0; i < k; i++) min_sum += nums[i];
//         for (int i = n - k; i < n; i++) max_sum += nums[i];
//         return max_sum - min_sum;
//     }
// };

class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> freq(101);
        for (int v: nums) freq[v]++;
        int max_sum = 0, min_sum = 0;
        int count = k;

        for (int i = 1; i <= 100; i++) {
            if (freq[i] > 0) {
                int max_loss = min(count, freq[i]);
                min_sum += i * max_loss;
                count -= max_loss;
                if (count == 0) break;
            }
        }

        count = k;
        for (int i = 100; i >= 1; i--) {
            if (freq[i] > 0) {
                int max_loss = min(count, freq[i]);
                max_sum += i * max_loss;
                count -= max_loss;
                if (count == 0) break;
            }
        }
        return max_sum - min_sum;
    }
};

