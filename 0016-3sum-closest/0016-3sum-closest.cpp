class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int minDiff = INT_MAX;
        int minDiffSum = -1;
        int n = nums.size();

        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    int s = nums[i] + nums[j] + nums[k];
                    int currentDiff = abs(target - s);
                    if (currentDiff < minDiff) {
                        minDiff = currentDiff;
                        minDiffSum = s;
                    }
                }
            }
        }
        return minDiffSum;
    }
};