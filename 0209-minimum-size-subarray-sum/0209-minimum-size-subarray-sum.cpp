class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start = 0, end = 0;
        int minLength = INT_MAX;
        int currentSum = 0;

        while (end < nums.size()) {
            currentSum += nums[end];
            while (currentSum >= target) {
                minLength = min(minLength, end - start + 1);
                currentSum -= nums[start];
                start++;
            }
            end++;
        }

        return minLength == INT_MAX ? 0 : minLength;
    }
};