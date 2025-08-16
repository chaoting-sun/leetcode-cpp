class Solution {
public:
    // Approach: binary search to find the mid that is larger then the right
    // Tutorial: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/solutions/158940/beat-100-very-simple-python-very-detailed-explanation
    // int findMin(vector<int>& nums) {
    //     int left = 0, right = nums.size() - 1;

    //     while (left < right) {
    //         int mid = left + (right - left) / 2;
    //         if (nums[mid] > nums[right]) {
    //             left = mid + 1;
    //         } else {
    //             right = mid;
    //         }
    //     }
    //     return nums[right];
    // }

    int findMin(vector<int>& nums) {
        if (nums[0] < nums[nums.size() - 1]) {
            return nums[0];
        }
        
        int left = 0, right = nums.size() - 1;

        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= nums[right]) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return nums[right];
    }
};
