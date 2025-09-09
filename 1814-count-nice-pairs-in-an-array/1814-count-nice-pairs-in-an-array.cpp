class Solution {
public:
    // Approach:
    // nums[i] + rev(nums[j]) == nums[j] + rev(nums[i]) -> nums[i] - rev(nums[i]) = nums[j] - rev(nums[j])
    // find the same computed result of nums[i] + rev(nums[j])

    int reverse(int num) {
        int rev = 0;
        while (num > 0) {
            rev = rev * 10 + num % 10;
            num /= 10;
        }
        return rev;
    }

    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> value_count; // value: count
        const int MOD = 1e9 + 7;
        int count = 0;        
        for (int i = 0; i < (int)nums.size(); i++) {
            int result = nums[i] - reverse(nums[i]);
            if (value_count.count(result)) {
                count += value_count[result];
                count %= MOD;
            }
            value_count[result]++;
        }

        return count;
    }
};

