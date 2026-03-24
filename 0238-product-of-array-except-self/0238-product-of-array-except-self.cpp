// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int n = nums.size();
        
//         vector<int> prefix_product(n), suffix_product(n);
//         prefix_product[0] = nums[0];
//         suffix_product[n - 1] = nums[n - 1];

//         for (int i = 1; i < n; i++) prefix_product[i] = prefix_product[i - 1] * nums[i];
//         for (int i = n - 2; i >= 0; i--) suffix_product[i] = suffix_product[i + 1] * nums[i];

//         vector<int> ans(n);
//         for (int i = 0; i < n; i++) {
//             int prefix = i == 0 ? 1 : prefix_product[i - 1];
//             int suffix = i == n - 1 ? 1 : suffix_product[i + 1];
//             ans[i] = prefix * suffix;
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        ans[0] = 1;
        int prefix = nums[0];
        for (int i = 1; i < n; i++) {
            ans[i] = prefix;
            prefix *= nums[i];
        }
        int suffix = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            ans[i] *= suffix;
            suffix *= nums[i];
        }

        return ans;
    }
};
