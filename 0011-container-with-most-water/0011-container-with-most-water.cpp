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

    // Approach2: Two Pointers
    // We want to maximize the area formed between two lines. The area is determined
    // by the shorter height between the two lines and the distance (width) between them.
    // 
    // To cover all possibilities efficiently, we start with the widest container:
    // left pointer at index 0 and right pointer at index n - 1. On each step, we compute
    // the current area and update the maximum.
    // 
    // To potentially find a larger area, we move the pointer at the side with the
    // smaller height inward. This is because the area is limited by the shorter line,
    // and moving the taller line inward cannot increase the min height. Shrinking
    // the width without increasing the min height will only reduce the area.
    // 
    // We repeat until the two pointers meet.
    // Time: O(n), where n is the length of height
    // Space: O(1)    

    // bad example that works (first version)

    // int maxArea(vector<int>& height) {
    //     int n = height.size();
    //     int left = 0;
    //     int right = n - 1;
        
    //     int max_amount = min(height[0], height[n - 1]) * (n - 1);

    //     while (left < right) {
    //         if (height[left] < height[right]) {
    //             while (left < right && height[left] >= height[left + 1]) left++;
    //             left++;
    //         } else if (height[left] > height[right]) {
    //             while (left < right && height[right - 1] <= height[right]) right--;
    //             right--;
    //         } else {
    //             if (height[left + 1] > height[right - 1]) {
    //                 left++;
    //             } else {
    //                 right--;
    //             }
    //         }
    //         int amount = min(height[left], height[right]) * (right - left);
    //         max_amount = max(amount, max_amount);
    //     }

    //     return max_amount;
    // }

    // cleaner example that works

    // In most standard two-pointer problems, there is only one while loop controlling
    // the movement of the poniters, and no nested while inside it.
    // - The classic two-pointer pattern moves one pointer by exactly one step per iteration.
    // - Each step eliminates one potential pair, ensuring the algorithm runs in O(n).
    // - Adding a nested while to skip indices can accidentally skip valid candidates and
    // break correctness unless it’s mathematically guaranteed those skipped ones cannot
    // produce a better answer (which in this problem is not guaranteed).

    // Problems like "Remove Duplicates from Sorted Array", "3Sum" sometimes use an inner while to skip duplicates, but that’s for a different purpose (avoiding repeated results).
    // In Container With Most Water, inner while loops to skip heights are not part of the optimal solution.

    // Correct pattern:
    // while (left < right) {
    //     update max area;
    //     move one pointer inward;
    // }

    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n - 1;
        int max_amount = 0;
        
        while (left < right) {
            int w = right - left;
            int h = min(height[left], height[right]);
            int amount = w * h;

            max_amount = max(max_amount, amount);

            if (height[left] >= height[right]) {
                right--;
            } else {
                left++;
            }
        }

        return max_amount;
    }
};