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

    // Approach2: Sort + Fix one + Hash table
    // Time: O(n**2)
    // Space: O(n) -> seen

    // vector<vector<int>> threeSum(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<vector<int>> ans;

    //     sort(nums.begin(), nums.end());

    //     for (int i = 0; i < n; i++) {
    //         if (i != 0 && nums[i] == nums[i - 1]) continue;

    //         unordered_set<int> seen;
    //         int j = i + 1;

    //         while (j < n) {
    //             int target = - (nums[i] + nums[j]);
    //             if (seen.count(target)) {
    //                 ans.push_back({ nums[i], target, nums[j] });
    //                 // move to the last one of the repeated numbers
    //                 while (j < nums.size() - 1 && nums[j] == nums[j + 1]) j++;
    //             }
    //             seen.insert(nums[j]);
    //             j++;
    //         }
    //     }
        
    //     return ans;
    // }

    // Approach3: Sort + Fix one + Two Pointers
    // Time: O(n**2)
    // Space: O(1)

    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        unordered_map<int,int> valueIndex;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < (int)nums.size(); i++) {
            if (i > 0 && nums[i - 1] == nums[i]) continue;

            int target = -nums[i];
            int left = i + 1, right = n - 1;
            while (left < right) {
                int added = nums[left] + nums[right];
                if (added > target) {
                    right--;
                } else if (added < target) {
                    left++;
                } else {
                    ans.push_back({ nums[i], nums[left], nums[right] });
                    left++;
                    right--;
                    while (nums[left-1] == nums[left] && left < right) left++;
                    while (nums[right] == nums[right + 1] && left < right) right--;
                }
            }
        }
        return ans;
    }

    // Used for next practice

    // vector<vector<int>> threeSum(vector<int>& nums) {

    // }
};

// [-3 2 0 1 2 -3] -> [-3, 1, 2]
//  |

// [-3 2 0 1 2 -3] -> [2, 1, -3]
//     |

// [-3 -3 0 1 2 2] -> [-3, 1, 2]
//   |
// [-3 -3 0 1 2 2]
//      |
