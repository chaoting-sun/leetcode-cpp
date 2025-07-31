class Solution {
public:
    // Approach1: brute-force -> TLE
    // Time: O(n^3), where n is the length of nums
    // Space: O(n^3)

    // vector<vector<int>> threeSum(vector<int>& nums) {
    //     int n = nums.size();
    //     set<vector<int>> res;
    //     vector<vector<int>> ans;
        
    //     for (int i = 0; i < n - 2; i++) {
    //         for (int j = i + 1; j < n - 1; j++) {
    //             for (int k = j + 1; k < n; k++) {
    //                 if (nums[i] + nums[j] + nums[k] == 0) {
    //                     vector<int> group {nums[i], nums[j], nums[k]};
    //                     sort(group.begin(), group.end());
    //                     if (res.find(group) == res.end()) {
    //                         res.insert(group);
    //                         ans.push_back(group);
    //                     }
    //                 }
    //             }
    //         }
    //     }
        
    //     return ans;
    // }

    // Approach2: Sort + Fix one + Two Pointers
    // Time: O(n**2)
    // Space: O(1)

    // vector<vector<int>> threeSum(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<vector<int>> ans;

    //     sort(nums.begin(), nums.end());

    //     for (int i = 0; i < n - 2; i++) {
    //         if (i != 0 && nums[i] == nums[i - 1]) continue;

    //         int target = 0 - nums[i];
    //         int left = i + 1, right = n - 1;
            
    //         while (left < right) {
    //             // most important condition: if the current value is the same as its previous,
    //             // then the combination including it's value, if exists, should have been processed.
    //             if (left != i + 1 && nums[left - 1] == nums[left]) {
    //                 left++;
    //                 continue;
    //             }
    //             if (right != nums.size() - 1 && nums[right] == nums[right + 1]) {
    //                 right--;
    //                 continue;
    //             }
    //             int sum = nums[left] + nums[right];
    //             if (sum > target) {
    //                 right--;
    //             } else if (sum < target) {
    //                 left++;
    //             } else {
    //                 ans.push_back({ nums[i], nums[left], nums[right] });
    //                 right--;
    //                 left++;
    //             }
    //         }
    //     }
    //     return ans;
    // }

    // Approach2: Sort + Fix one + Hash table
    // Time: O(n**2)
    // Space: O(1)

    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {
            if (i != 0 && nums[i] == nums[i - 1]) continue;

            unordered_set<int> seen;
            int j = i + 1;

            while (j < n) {
                int expected_k_val = - (nums[i] + nums[j]);
                if (seen.find(expected_k_val) != seen.end()) {
                    ans.push_back({ expected_k_val, nums[i], nums[j] });
                    while (j < nums.size() - 1 && nums[j] == nums[j + 1]) j++;
                }
                seen.insert(nums[j]);
                j++;
            }
        }
        
        return ans;
    }
};