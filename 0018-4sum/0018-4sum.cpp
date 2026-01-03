// Approach: Recursion + Two-Sum Solution
// Time: O(n^3). if k == 2, we take O(n) to find the solution. for k == 4, we needs O(n^3)
// Space: O(1)

using ll = long long;

class Solution {
private:
    vector<vector<int>> ans;

    bool tooLarge(int k, int i, ll target, vector<int>& nums) {
        int n = nums.size();
        ll maxSum = nums[i];
        for (int j = 1; j < k; j++) maxSum += nums[n - j];
        return maxSum < target;
    }

    bool tooSmall(int k, int i, ll target, vector<int>& nums) {
        ll minSum = nums[i];
        for (int j = 1; j < k; j++) minSum += nums[i + j];
        return minSum > target;
    }

public:
    void kSum(int k, int start, ll target, vector<int>& nums, vector<int>& subset) {
        int n = nums.size();
        if (k > 2) {
            for (int i = start; i < n - k + 1; i++) {
                if (i > start && nums[i - 1] == nums[i]) continue;
                if (tooSmall(k, i, target, nums)) break;
                if (tooLarge(k, i, target, nums)) continue;
                
                subset.push_back(nums[i]);
                kSum(k - 1, i + 1, target - nums[i], nums, subset);
                subset.pop_back();
            }
            return;
        }

        // Two Sum Method: Two Pointers
        int left = start, right = n - 1;
        while (left < right) {
            ll addedSum = nums[left] + nums[right];
            if (addedSum > target) {
                right--;
            } else if (addedSum < target) {
                left++;
            } else {
                subset.push_back(nums[left]);
                subset.push_back(nums[right]);
                ans.push_back(subset);
                right--;
                left++;
                while (right > left && nums[right] == nums[right + 1]) right--;
                while (right > left && nums[left - 1] == nums[left]) left++;
                subset.pop_back();
                subset.pop_back();
            }
        }
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> subset;
        subset.reserve(4);
        kSum(4, 0, (ll)target, nums, subset);
        return ans;
    }
};