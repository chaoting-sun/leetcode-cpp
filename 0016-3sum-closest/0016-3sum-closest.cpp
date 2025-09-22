class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int minDiff = INT_MAX;
        int minDiffSum = -1;
        int n = nums.size();

        for (int i = 0; i < n - 2; i++) {
            int left = i + 1, right = n - 1;
            while (left < right) {
                int threeSum = nums[i] + nums[left] + nums[right];
                int currentDiff = abs(target - threeSum);
                if (currentDiff < minDiff) {
                    minDiff = currentDiff;
                    minDiffSum = threeSum;
                }
                if (threeSum > target) {
                    right--;
                } else if (threeSum < target) {
                    left++;
                } else {
                    return target;
                }
            }
        }
        return minDiffSum;
    }
};