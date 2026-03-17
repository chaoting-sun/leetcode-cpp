class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return {};
        
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i <= n - 3; i++) {
            // the fixed value is the same as the previous one, we ignore it for deduplication
            if (i != 0 && nums[i] == nums[i - 1]) continue;

            // solve the two sum problem with two pointers
            int left = i + 1;
            int right = n - 1;
            int target = -nums[i];

            while (left < right) {
                int s = nums[left] + nums[right];
                if (s > target) {
                    right--;
                } else if (s < target) {
                    left++;
                } else {
                    ans.push_back({ nums[i], nums[left], nums[right] });
                    left++;
                    right--;
                    // avoid the duplicates
                    while (left < right && nums[left - 1] == nums[left]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                }
            }
        }

        return ans;
    }
};