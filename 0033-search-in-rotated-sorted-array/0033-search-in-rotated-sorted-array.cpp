class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        int min_id = right;
        if (min_id == 0) {
            left = 0;
            right = n;
        } else {
            if (nums[min_id] <= target && target <= nums[n - 1]) {
                left = min_id;
                right = n;
            } else if (nums[0] <= target && target <= nums[min_id - 1]) {
                left = 0;
                right = min_id;
            } else {
                return -1;
            }
        }

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right = mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                return mid;
            }
        }

        return -1;
    }
};