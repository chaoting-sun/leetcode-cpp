using ll = long long;

class Solution {
private:
    vector<vector<int>> ans;

public:
    void kSum(int k, int start, ll target, vector<int>& nums, vector<int>& subset) {
        int n = nums.size();
        if (k > 2) {
            for (int i = start; i < n - k + 1; i++) {
                if (i > start && nums[i - 1] == nums[i]) continue;
                subset.push_back(nums[i]);
                kSum(k - 1, i + 1, target - nums[i], nums, subset);
                subset.pop_back();
            }
            return;
        }

        int left = start, right = n - 1;
        while (left < right) {
            int addedSum = nums[left] + nums[right];
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
        
        int start = 0, k = 4;
        vector<int> subset;
        kSum(k, start, target, nums, subset);
        return ans;
    }
};