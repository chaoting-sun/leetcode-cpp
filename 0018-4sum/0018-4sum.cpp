class Solution {
private:
    vector<vector<int>> ans;

    void kSum(int k, const vector<int>& nums, vector<int>& subset, long long target, int start_idx) {
        int n = nums.size();

        if (start_idx + k > n) return;

        if (target < (long long)nums[start_idx] * k) return;
        if (target > (long long)nums.back() * k) return;

        if (k == 2) {
            int left = start_idx;
            int right = n - 1;

            while (left < right) {
                long long current = (long long)nums[left] + nums[right];
                if (current > target) {
                    right--;
                } else if (current < target) {
                    left++;
                } else {
                    vector<int> temp = subset;
                    temp.push_back(nums[left]);
                    temp.push_back(nums[right]);
                    ans.push_back(temp);
                    left++;
                    right--;
                    while (left < right && nums[left - 1] == nums[left]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                }
            }
            return;
        }

        for (int i = start_idx; i <= n - k; i++) {
            if (i > start_idx && nums[i - 1] == nums[i]) continue;
            subset.push_back(nums[i]);
            kSum(k - 1, nums, subset, target - nums[i], i + 1);
            subset.pop_back();
        }
    }

public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 4) return {};
        
        sort(nums.begin(), nums.end());
        vector<int> subset;
        kSum(4, nums, subset, target, 0);
        return ans;
    }
};