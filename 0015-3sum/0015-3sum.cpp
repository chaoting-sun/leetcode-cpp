class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int length = nums.size();
        if (length <= 2) return {};
        
        sort(nums.begin(), nums.end());

        vector<vector<int>> results;
        for (int i = 0; i < length; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = length - 1;
            int target = 0 - nums[i];
            while (left < right) {    
                int current_sum = nums[left] + nums[right];
                if (current_sum > target) {
                    right--;
                } else if (current_sum < target) {
                    left++;
                } else {
                    results.push_back({ nums[i], nums[left], nums[right] });
                    left++;
                    right--;
                    while (left < right && nums[left - 1] == nums[left]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                }
            }
        }
        return results;
    }
};