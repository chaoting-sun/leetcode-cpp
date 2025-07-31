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

    // Approach2: Fix one, and see the problem as a two-sum problem -> TLE
    // Time: O(n^2*log(n)), where n is the length of nums
    // Note that find in set takes O(log(m)) where m is the number of elements in the set.
    // For each pair (i, j) in nums, they at most produce one k s.t. nums[i] + nums[j] + nums[k] = 0.
    // There are n*(n-1)/2 pairs, so m should be less than n^2. That is, find in set takes O(log(n^2))
    // = O(2*log(n)) = O(log(n))
    // Space: O(n^3)

    // vector<vector<int>> threeSum(vector<int>& nums) {
    //     int n = nums.size();
    //     set<vector<int>> set;
    //     vector<vector<int>> ans;
        
    //     for (int i = 0; i < n - 2; i++) {
    //         unordered_map<int, int> map;

    //         for (int j = i + 1; j < n; j++) {
    //             // find a value k in map s.t. nums[k] = - nums[i] - nums[j]
    //             // that is, nums[i] + nums[j] + nums[k] = 0
    //             bool find_group = map.find(- nums[i] - nums[j]) != map.end();
    //             if (find_group) {
    //                 vector<int> group { nums[i], nums[j], - nums[i] - nums[j] };
    //                 sort(group.begin(), group.end());
    //                 if (set.find(group) == set.end()) {
    //                     set.insert(group);
    //                     ans.push_back(group);
    //                 }
    //             }
    //             map.insert(make_pair(nums[j], j));
    //         }
    //     }
        
    //     return ans;
    // }

    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {
            if (i != 0 && nums[i] == nums[i - 1]) continue;

            vector<int> rest;
            for (int j = i + 1; j < n; j++) rest.push_back(nums[j]);
            
            int target = 0 - nums[i];
            int left = 0, right = rest.size() - 1;
            
            while (left < right) {
                if (left != 0 && rest[left - 1] == rest[left]) {
                    left++;
                    continue;
                }
                if (right != rest.size() - 1 && rest[right] == rest[right + 1]) {
                    right--;
                    continue;
                }
                int sum = rest[left] + rest[right];
                if (sum > target) {
                    right--;
                } else if (sum < target) {
                    left++;
                } else {
                    ans.push_back({ nums[i], rest[left], rest[right] });
                    right--;
                    left++;
                }
            }
        }
        
        return ans;
    }
};