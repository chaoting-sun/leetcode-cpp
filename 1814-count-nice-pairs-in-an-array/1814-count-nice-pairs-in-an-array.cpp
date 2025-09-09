class Solution {
public:
    // Approach:
    // nums[i] + rev(nums[j]) == nums[j] + rev(nums[i]) -> nums[i] - rev(nums[i]) = nums[j] - rev(nums[j])
    // find the same computed result of nums[i] + rev(nums[j])

    int reverse(int num) {
        if (num == 0) return 0;
        while (num % 10 == 0) num /= 10;
        int digits = 0;
        while (pow(10, digits) <= num) digits++;
        int rev = 0;
        while (num > 0) {
            rev += (num % 10) * (int)pow(10, digits - 1);
            num /= 10;
            digits--;
        }
        return rev;
    }

    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> value_count; // value: count
        for (int i = 0; i < (int)nums.size(); i++) {
            int result = nums[i] - reverse(nums[i]);
            value_count[result]++;
        }
        long long count = 0;
        for (auto [_, current_count]: value_count) {
            count += (long long)current_count * (current_count - 1) / 2;
            count %= (long long)pow(10, 9) + 7;
        }
        return (int)count;
    }
};

