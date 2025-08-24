class Solution {
public:
    // Approach: DP (Kadane's Algorithm)

    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int min_so_far = nums[0];
        int max_so_far = nums[0];
        int max_product = max_so_far;

        for (int i = 1; i < n; i++) {
            int tmp_max_so_far = max(nums[i], max(max_so_far*nums[i], min_so_far*nums[i]));
            min_so_far = min(nums[i], min(max_so_far*nums[i], min_so_far*nums[i]));
            
            max_so_far = tmp_max_so_far;

            max_product = max(max_product, max_so_far);
        }

        return max_product;
    }
};