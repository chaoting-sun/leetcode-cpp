class Solution {
public:
    // Approach: DP (Kadane's Algorithm)
    // Since multiplying by a negative number can flip a maximum into a minimum (and vice versa),
    // we keep track of both the maximum and minimum product at each step

    // int maxProduct(vector<int>& nums) {
    //     int n = nums.size();
    //     if (n == 0) return 0;

    //     int min_so_far = nums[0];
    //     int max_so_far = nums[0];
    //     int max_product = max_so_far;

    //     for (int i = 1; i < n; i++) {
    //         int tmp_max_so_far = max(nums[i], max(max_so_far*nums[i], min_so_far*nums[i]));
    //         min_so_far = min(nums[i], min(max_so_far*nums[i], min_so_far*nums[i]));
            
    //         max_so_far = tmp_max_so_far;

    //         max_product = max(max_product, max_so_far);
    //     }

    //     return max_product;
    // }

    // int maxProduct(vector<int>& nums) {
    //     int n = nums.size();
    //     if (n == 0) return 0;
        
    //     vector<int> minProduct(n), maxProduct(n); 
    //     minProduct[0] = maxProduct[0] = nums[0];
    //     int ans = nums[0];

    //     for (int i = 1; i < n; i++) {
    //         maxProduct[i] = max(nums[i], max(minProduct[i - 1] * nums[i], maxProduct[i - 1] * nums[i]));
    //         minProduct[i] = min(nums[i], min(minProduct[i - 1] * nums[i], maxProduct[i - 1] * nums[i]));
    //         ans = max(ans, maxProduct[i]);
    //     }
    //     return ans;
    // }

      int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        int ans = nums[0];
        int minProduct = nums[0], maxProduct = nums[0];

        for (int i = 1; i < n; i++) {
            int lastMinProduct = minProduct;
            int lastMaxProduct = maxProduct;
            maxProduct = max(nums[i], max(lastMinProduct * nums[i], lastMaxProduct * nums[i]));
            minProduct = min(nums[i], min(lastMinProduct * nums[i], lastMaxProduct * nums[i]));
            ans = max(ans, maxProduct);
        }
        return ans;
    }
};