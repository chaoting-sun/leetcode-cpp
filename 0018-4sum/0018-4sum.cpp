class Solution {
private:
    void threeSum(const vector<int>& nums, vector<vector<int>>& results, int start_idx, int target) {
        int length = nums.size();

        long long target_3sum = target - nums[start_idx];

        for (int i = start_idx + 1; i < length; i++) {
            // avoid repetition of the first number
            if (i > start_idx + 1 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = length - 1;
            long long target_2sum = target_3sum - nums[i];
            while (left < right) {    
                long long current_sum = nums[left] + nums[right];
                if (current_sum > target_2sum) {
                    right--;
                } else if (current_sum < target_2sum) {
                    left++;
                } else {
                    results.push_back({ nums[start_idx], nums[i], nums[left], nums[right] });
                    left++;
                    right--;
                    // avoid repetition of the second number
                    while (left < right && nums[left - 1] == nums[left]) left++;
                    // avoid repetition of the third number
                    while (left < right && nums[right] == nums[right + 1]) right--;
                }
            }
        }
    }
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int length = nums.size();
        if (length < 4) return {};
        
        sort(nums.begin(), nums.end());

        vector<vector<int>> results;
        for (int i = 0; i <= nums.size() - 4; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            threeSum(nums, results, i, target);
        }
        return results;
    }
};