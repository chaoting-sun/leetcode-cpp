class Solution {
public:
    // Brute-force -> TLE
    // Time: O(n^2), where n is the length of height
    // Space: O(1)
    // int maxArea(vector<int>& height) {
    //     int n = height.size();
    //     int max_amount = 0;
    //     for (int i = 0; i < n - 1; i++) {
    //         for (int j = i; j < n; j++) {
    //             int amount = min(height[i], height[j]) * (j - i);
    //             if (amount > max_amount) max_amount = amount;
    //         }
    //     }
    //     return max_amount;
    // }

    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n - 1;
        
        int max_amount = min(height[0], height[n - 1]) * (n - 1);

        while (left < right) {
            if (height[left] < height[right]) {
                while (left < right && height[left] >= height[left + 1]) left++;
                left++;
            } else if (height[left] > height[right]) {
                while (left < right && height[right - 1] <= height[right]) right--;
                right--;
            } else {
                if (height[left + 1] > height[right - 1]) {
                    left++;
                } else {
                    right--;
                }
            }
            int amount = min(height[left], height[right]) * (right - left);
            max_amount = max(amount, max_amount);
        }

        return max_amount;
    }
};

// [1,8,6,8,7]
//  l       r