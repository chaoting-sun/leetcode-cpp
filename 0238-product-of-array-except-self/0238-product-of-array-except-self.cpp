class Solution {
public:
    // Approach1: brute-force. sequentially do all the products for all elements -> TLE
    // time: O(n**2)
    // space: O(1)

    // vector<int> productExceptSelf(vector<int>& nums) {
    //     vector<int> ans;

    //     for (int i = 0; i < nums.size(); i++) {
    //         int product = 1;
    //         for (int j = 0; j < nums.size(); j++) {
    //             if (j != i) product *= nums[j];
    //         }
    //         ans.push_back(product);
    //     }
    //     return ans;
    // }

    // Approach2: brute-force. sequentially do all the products for all elements -> TLE
    // time: O(n**2)
    // space: O(1)

    vector<int> productExceptSelf(vector<int>& nums) {
        // count the number of 0s
        vector<int> zero_pos{};
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) zero_pos.push_back(i);
        }

        vector<int> ans(n);

        // handle 3 cases:
        // 1. ans should be all 0s when there are at least two 0s.
        if (zero_pos.size() >= 2) return ans;
        // 2. only index = zero_pos[0] has non-zero value in ans.
        else if (zero_pos.size() == 1) {
            int product = 1;
            for (int i = 0; i < n; i++) {
                if (i != zero_pos[0]) product *= nums[i];
            }
            ans[zero_pos[0]] = product;
            return ans;
        }

        int total_product = 1;
        for (int n: nums) total_product *= n;
        for (int i = 0; i < n; i++) {
            ans[i] = total_product / nums[i];
        }
        return ans;
    }
};