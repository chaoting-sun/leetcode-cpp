class Solution {
public:
    // Approach: find the index of the smallest value, and based on the target, selecting the
    // interval in left or right hand side
    // Find the min in sorted array: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

    // int search(vector<int>& nums, int target) {
    //     int n = nums.size();
    //     int left = 0, right = n - 1;

    //     while (left < right) {
    //         int mid = left + (right - left) / 2;
    //         if (nums[mid] > nums[right]) {
    //             left = mid + 1;
    //         } else {
    //             right = mid;
    //         }
    //     }

    //     int pivot = right;
    //     if (nums[pivot] <= target && target <= nums[n - 1]) {
    //         left = pivot;
    //         right = n;
    //     } else {
    //         left = 0;
    //         right = pivot;
    //     }

    //     while (left < right) {
    //         int mid = left + (right - left) / 2;
    //         if (nums[mid] > target) {
    //             right = mid;
    //         } else if (nums[mid] < target) {
    //             left = mid + 1;
    //         } else {
    //             return mid;
    //         }
    //     }

    //     return -1;
    // }

    // Approach: One pass binary search

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            // When the condition satisfies, the interval [left, mid] is not rotated.
            // so if the target is between the nums[left] and nums[mid], it must be in the interval if it exists.
            // if it is not between the two, then search in the right hand side
            
            // Edge case: mid may be equal to left, so we should use "<=" rather than "<" to handle the case that target == nums[mid]
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            // In this case, [left, mid] is a rotated array.
            // Because the right hand side is not rotated, so we check if target is between nums[mid] and nums[right].
            // If it is true, then search in the right, or else the left.
            else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }       

        return -1;
    }
};